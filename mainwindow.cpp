#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m(QSize(400,400),QImage::Format_RGB32)//constructor for heatmap
{
    ui->setupUi(this);
    scene = new QGraphicsScene(); //create empty scene


    vec.push_back(DataPoint(QPoint(150,150),10));
    vec.push_back(DataPoint(QPoint(250,250),10));
    QTime time;
    time.start();

    m.genMap2(vec);
    //Creates a gradient in grayscale (this was for experimental purposes)
    cout<<time.elapsed()<<endl;

    scene->setSceneRect(m.rect()); //set the scene's view rectangle to the image's
    pix = QPixmap::fromImage(m); //create a pixmap from the image
    pix = pix.scaled(ui->renderView->size());
    scene->addPixmap(pix); //add the pixmap to the scene
    ui->renderView->setSceneRect(pix.rect()); //set the renderviews view rectangle
    ui->renderView->setScene(scene); //set the renderViews scene
    //added comment to check something in git.
}
void MainWindow::update(){
    cout<<"update"<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

