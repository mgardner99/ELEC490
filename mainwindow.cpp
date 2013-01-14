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

    //Creates a gradient in grayscale (this was for experimental purposes)
    for(int i = 0; i < m.size().width(); i++){
        for (int j = 0; j< m.size().height(); j++){
            QColor c((i/(float)m.size().width()*255),(i/(float)m.size().width()*255),(i/(float)m.size().width()*255));
            m.setPixel(i,j,c.rgb());
        }
    }

    scene->setSceneRect(m.rect()); //set the scene's view rectangle to the image's
    QPixmap pix = QPixmap::fromImage(m); //create a pixmap from the image
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

