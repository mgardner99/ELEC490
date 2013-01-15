#include "DataPoint.h"

DataPoint::DataPoint(int x, int y, float v){
    DataPoint(QPoint(x,y),v);
}
DataPoint::DataPoint(QPoint l, float v){
    setLocation(l);
    setVal(v);
}

float DataPoint::getVal(){
    return val;
}

QPoint DataPoint::getLocation(){
    return location;
}

int DataPoint::getX(){
    return location.x();
}

int DataPoint::getY(){
   return location.y();
}

void DataPoint::setLocation(int x, int y){
    setLocation(QPoint(x,y));
}

//should probably add some error checking here
void DataPoint::setLocation(QPoint p){
    location = p;
}

//should probably add some error checking here
void DataPoint::setVal(float v){
    val = v;
}

float DataPoint::getDist(int x, int y){
    return qSqrt(qPow(y-location.y(),2)+qPow(x-location.x(),2));
}
