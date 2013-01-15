#ifndef HEATMAP_H
#define HEATMAP_H

#include <QImage>
#include <vector>
#include <QColor>
#include "DataPoint.h"
#include <iostream>

using namespace std;

class HeatMap
{

public:
    HeatMap(QSize size, QImage::Format form);
    QImage getImg();
    void genMap(vector<DataPoint> vec);

    static const float RADC = 10; //fudge factor for pressure algorithm

private:
    QImage* img;
    

    
};

#endif // HEATMAP_H
