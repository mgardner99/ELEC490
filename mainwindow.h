/*
  2013-2014
  Megan Gardner
  for ELEC 490
  Group Members: Kevin Cook
                 Megan Gardner
                 Cameron Kramer

  2012-2013
  Joey Frohlinger
  for ELEC 490
  Group Members:    Bren Piper
                    Adam Bunn
                    Joey Frohlinger
  Supervisor:       Dr. Evelyn Morin

  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include "heatmap.h"
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QTimer>
#include "DataPoint.h"
#include "Communication.h"
//#include <phonon/phonon> //defunct
#include <QThread>
#include <QShortcut>
#include <QFileDialog>
#include <QMultimedia>
#include <QtWidgets>
#include <QtMultimediaWidgets>


namespace Ui {
class MainWindow;
}

class QGraphicsVideoItem;
class QSlider;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    HeatMap m;
    HeatMap m2;
    vector<DataPoint>* vec;
    vector<DataPoint>* vec2;
    QPixmap pix;
    QPixmap pix2;
    QGraphicsScene *Lscene;
    QGraphicsScene *Rscene;
    QGraphicsItem* pixItem;
    QGraphicsItem* pixItem2;
    float fudger; // what is this "fudger" for?
    QImage LFootMask;
    QImage RFootMask;
    QThread* commThread;
    Communication* comm;
    //Phonon::VideoPlayer *vidPlayer; - defunct
    //Phonon::SeekSlider *vidSeek; - defunct
    bool vidLoaded;
    QString vidPathText;
    QMediaPlayer mediaPlayer;
    QSlider *vidSeek;
    QSlider *rotate;
    QShortcut *leftArrow;
    QShortcut *rightArrow;

    QString currentComPort;

    QGraphicsVideoItem *videoItem;


    void uiInit();

 private slots:
    void update();
    void commTimer();
    void vidTime();
    void on_comPortBox_currentIndexChanged(const QString &arg1);

    void on_vidPlay_clicked();
    void on_vidPath_textEdited(const QString &arg1);
    void on_vidPause_clicked();

    void on_vidPath_returnPressed();
    void on_vidStartLoopSet_clicked();
    void on_vidEndLoopSet_clicked();
    void leftArrowSlot();
    void rightArrowSlot();
    void on_vidStop_clicked();
    void on_comPortBox_activated(const QString &arg1);


    void changeCom();
    void on_fileBrowserButton_clicked();
    void on_MainWindow_destroyed();
    void rotateVideo(int angle); // rotate video
};

#endif // MAINWINDOW_H
