#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <QPoint>
#include <QtCore/qmath.h>
class DataPoint{
public:
    DataPoint(QPoint l, float v);
    DataPoint(int x, int y, float v);

    float getVal();
    QPoint getLocation();

    int getX();
    int getY();

    void setVal(float v);
    void setLocation(QPoint p);
    void setLocation(int x, int y);

    float getDist(int x, int y); //gets the distance between the point and an image pixel.

private:
    QPoint location;
    float val;
};

#endif // DATAPOINT_H
