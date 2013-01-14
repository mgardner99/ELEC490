#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(); //create empty scene
    QImage m(QSize(400,400),QImage::Format_RGB32);
   // m.setPixel(100,100,0);
    QColor col(0,0,255);
    cout<<col.rgb()<<endl;
    m.setPixel(100,100,col.rgb());
    scene->setSceneRect(m.rect()); //set the scene's view rectangle to the image's
    QPixmap pix = QPixmap::fromImage(m); //create a pixmap from the image
    pix = pix.scaled(ui->renderView->size());
    QGraphicsPixmapItem* pixItem = scene->addPixmap(pix); //add the pixmap to the scene
    ui->renderView->setSceneRect(pix.rect()); //set the renderviews view rectangle
    ui->renderView->setScene(scene); //set the renderViews scene
}

MainWindow::~MainWindow()
{
    delete ui;
}

