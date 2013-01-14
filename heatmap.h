#ifndef HEATMAP_H
#define HEATMAP_H

#include <QImage>
#include <vector>
#include <QColor>
#include "DataPoint.h"

using namespace std;

class HeatMap
{

public:
    HeatMap(QSize size, QImage::Format form);
    QImage getImg();
    void genMap(vector<DataPoint> vec);
private:
    QImage* img;
    

    
};

#endif // HEATMAP_H
