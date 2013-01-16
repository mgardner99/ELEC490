/*
  Joey Frohlinger
  for ELEC 490
  Group Members:    Bren Piper
                    Adam Bunn
                    Joey Frohlinger
  Supervisor:       Dr. Evelyn Morin

  */

#ifndef HEATMAP_H
#define HEATMAP_H

#include <QImage>
#include <vector>
#include <QColor>
#include "DataPoint.h"
#include <iostream>
#include <QTimer>
#include <QWidget>
#include <QPainter>

using namespace std;

class HeatMap: public QImage
{

public:
    HeatMap(QSize size, QImage::Format form);
    //QImage getImg();
    void genMap(vector<DataPoint> vec);
    void update();
    static const float RADC = 10; //fudge factor for pressure algorithm

private:




};

#endif // HEATMAP_H
