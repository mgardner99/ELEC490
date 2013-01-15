#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <iostream>
#include "heatmap.h"
#include "DataPoint.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(); //create empty scene
    HeatMap m(QSize(400,400),QImage::Format_RGB32);
    vector<DataPoint> vec;
    vec.push_back(DataPoint(QPoint(150,150),10));
    vec.push_back(DataPoint(QPoint(250,250),10));
    m.genMap(vec);
    //Creates a gradient in grayscale (this was for experimental purposes)


    scene->setSceneRect(m.getImg().rect()); //set the scene's view rectangle to the image's
    QPixmap pix = QPixmap::fromImage(m.getImg()); //create a pixmap from the image
    pix = pix.scaled(ui->renderView->size());
    QGraphicsPixmapItem* pixItem = scene->addPixmap(pix); //add the pixmap to the scene
    ui->renderView->setSceneRect(pix.rect()); //set the renderviews view rectangle
    ui->renderView->setScene(scene); //set the renderViews scene
    //added comment to check something in git.
}

MainWindow::~MainWindow()
{
    delete ui;
}

