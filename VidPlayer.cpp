//New VideoPlayer class for 490 Project - due to defunct phonon
#include <QtMultimedia>
#include <QtWidgets>
//#include <QGraphicsVideoItem>

VidPlayer::VidPlayer(QWidget *parent) // constructor
    : QWidget(parent)
    , mediaPlayer(0, QMediaPlayer::VideoSurface)
    , videoItem(0)
    , playButton(0)
    , positionSlider(0)
{
    videoItem = new QGraphicsVideoItem;
    videoItem->setSize(QSizeF(400,400)); // set size of video

    connect(rotateSlider,SIGNAL(valueChanged(int)),this,SLOT(rotateVideo(int)));
    QAbstractButton *openButton = new QPushButton(tr("Open"));
    connect(openButton, Signal(clicked()), this, SLOT(openFile()));

    playButton = new QPushButton;
    playButton->setEnabled(false); // cannot click with no input
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    connect(playButton,SIGNAL(clicked()),this,SLOT(play()));

    positionSlider = new QSlider(Qt::Horizontal);
    positionSlider->setRange(0,0);
    connect(positionSlider,SIGNAL(sliderMoved(int)),this,SLOT(setPosition(int)));

    //Add components to video player
    QBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(openButton);
    controlLayout->addWidget(playButton);
    controlLayout->addWidget(positionSlider);

}

VideoPlayer::~VideoPlayer() // destructor
{

}

void VideoPlayer::openFile()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Movie"),QDir::homePath());
    if(!filename.isEmpty())
    {
        mediaPlayer.setMedia(QUrl::fromLocalFile(fileName));
        playButton->setEnabled(true); // enable play button
    }
}

void VideoPlayer::play() // play/pause toggle
{
    switch(mediaPlayer.state())
    {
    case QMediaPlayer::PlayingState:
        mediaPlayer.pause();
        break;
    default:
        mediaPlayer.play();
        break;
    }
}
