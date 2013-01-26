/*
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
#include "heatmap.h"
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QTimer>
#include "DataPoint.h"
#include "Communication.h"

#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

private:
    Ui::MainWindow *ui;
    HeatMap m;
    vector<DataPoint>* vec;
    QPixmap pix;
    QGraphicsScene *scene;
    QGraphicsItem* pixItem;
    float fudger;
    QImage footMask;
    QThread* commThread;
    Communication* comm;


    void uiInit();

 private slots:
    void update();
    void on_comPortBox_currentIndexChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
