/*
  Joey Frohlinger
  for ELEC 490
  Group Members:    Bren Piper
                    Adam Bunn
                    Joey Frohlinger
  Supervisor:       Dr. Evelyn Morin

  */

#include "heatmap.h"



HeatMap::HeatMap(QSize size, QImage::Format form):QImage(size,form){
   fill(QColor(255, 255, 255, 255)); //no longer necessary, done at the beginning of gen map, left in to cover my ass later
}

void HeatMap::genMap(vector<DataPoint> vec){
    float radius[vec.size()];
    fill(QColor(255, 255, 255, 255)); //blank out the picture

    QPainter paint(this); //if i try to save the initialization and make it a class var, the program crashes... compiler bug?
    paint.setRenderHint(QPainter::HighQualityAntialiasing); //why not

    for (int i = 0; i < vec.size(); i++){
        radius[i] = RADC*vec[i].getVal();
        //R = Px * C
    }

    QPen g_pen(QColor(0, 0, 0, 0));
    g_pen.setWidth(0);
    paint.setPen(g_pen);

    for (int i = 0; i < vec.size(); i++){
        QRadialGradient grad(vec[i].getLocation(), radius[i]); // Create Gradient
        grad.setColorAt(0, QColor(0, 0, 0, 255)); //This is the one I need to change when we have real data to make it relative to our formula
        grad.setColorAt(1, QColor(0, 0, 0, 0)); // Black, completely transparent
        QBrush g_brush(grad); // Gradient QBrush
        paint.setBrush(g_brush);
        paint.drawEllipse(vec[i].getLocation().x() - radius[i],vec[i].getLocation().y() - radius[i],2*radius[i],2*radius[i]);
    }
}


void HeatMap::update(){

}
