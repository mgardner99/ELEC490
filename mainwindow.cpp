#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

using namespace std;
/*
  Joey Frohlinger
  for ELEC 490
  Group Members:    Bren Piper
                    Adam Bunn
                    Joey Frohlinger
  Supervisor:       Dr. Evelyn Morin

  */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m(QSize(400,400),QImage::Format_RGB32)//constructor for heatmap

{
    ui->setupUi(this);
    fudger = 1; //remove me when when you have real data
    //timer based interrupt for screen rendering
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000/60); //60 hz frame rate (or so)

    comm = new Communication("COM5");
    QTimer* timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT( commUpdate() ));
    timer2->start(100);

    footMask.load("c:/footMask.png");
    scene = new QGraphicsScene(); //create empty scene


    vec = new vector<DataPoint>();
    vec->push_back(DataPoint(QPoint(150,150),0)); //remove these when you have actual data
    vec->push_back(DataPoint(QPoint(250,250),0));

    m.genMap(*vec);
    //Creates a gradient in grayscale (this was for experimental purposes)


    scene->setSceneRect(m.rect()); //set the scene's view rectangle to the image's
    pix = QPixmap::fromImage(m); //create a pixmap from the image
    pix = pix.scaled(ui->renderView->size());
    pixItem =  scene->addPixmap(pix); //add the pixmap to the scene
    ui->renderView->setSceneRect(pix.rect()); //set the renderviews view rectangle
    ui->renderView->setScene(scene); //set the renderViews scene
}

//update called from timer thread to lock frame rate
void MainWindow::update(){

/*
    if(vec->at(0).getVal() >= 10 || vec->at(0).getVal() <= 0){
            fudger = -fudger;
    }

    vec->at(0).setVal((vec->at(0).getVal()+fudger)); //remove this when you have actual data
*/

    m.genMap(*vec);
   // m.applyMask(footMask);
    scene->removeItem(pixItem);
    delete pixItem; //memory leak fix (What what!)
    pix = QPixmap::fromImage(m);
    pixItem = scene->addPixmap(pix);
}

void MainWindow::commUpdate(){
    comm->update();
    vec = comm->getData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

