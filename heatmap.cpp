#include "heatmap.h"

void HeatMap::genMap(vector<DataPoint> vec){
    float max = 0;
    float data[size().width()][size().height()];

    //init the data array
    for(int i =0; i < size().width(); i++){
        for (int j = 0; j < size().height(); j++){
            data[i][j] = 0;
        }
    }

    float radius[vec.size()];

    for (int i = 0; i < vec.size(); i++){
        radius[i] = RADC*vec[i].getVal();
        //R = Px * C
    }

    //calc all the pixel data values
    for(int i = 0; i < size().width(); i++){
        for (int j = 0; j< size().height(); j++){
            for(int k = 0; k < vec.size(); k++){ //vector loop
                float dist = vec[k].getDist(i,j);
                float numer = radius[k] - dist;

                if(numer > 0){
                    data[i][j] += vec[k].getVal()*(numer/radius[k]);
                    //Px*(R-D)/R
                }

                if(data[i][j] > max){
                    max = data[i][j];
                }
            }
        }
    }

    //normalize and draw the data
    for(int i = 0; i < size().width(); i++){
        for (int j = 0; j< size().height(); j++){
            QColor c(255-data[i][j]/max*255,255-data[i][j]/max*255,255-data[i][j]/max*255);
            setPixel(i,j,c.rgb());
        }
    }
}

HeatMap::HeatMap(QSize size, QImage::Format form):QImage(size,form){
    fill(QColor(255, 255, 255, 255));
   // paint.setRenderHint(QPainter::HighQualityAntialiasing);
}

void HeatMap::genMap2(vector<DataPoint> vec){
    float radius[vec.size()];
    QPainter paint(this);
    paint.setRenderHint(QPainter::HighQualityAntialiasing);
    for (int i = 0; i < vec.size(); i++){
        radius[i] = RADC*vec[i].getVal();
        //R = Px * C
    }

    for (int i = 0; i < vec.size(); i++){
        QPen g_pen(QColor(0, 0, 0, 0));
        g_pen.setWidth(0);
        QRadialGradient grad(vec[i].getLocation(), radius[i]); // Create Gradient
        grad.setColorAt(0, QColor(0, 0, 0, 255)); // Black, varying alpha
        grad.setColorAt(1, QColor(0, 0, 0, 0)); // Black, completely transparent
        QBrush g_brush(grad); // Gradient QBrush
        paint.setPen(g_pen);
        paint.setBrush(g_brush);
        paint.drawEllipse(vec[i].getLocation().x() - radius[i],vec[i].getLocation().y() - radius[i],2*radius[i],2*radius[i]);
    }
}


void HeatMap::update(){
   /* // Setup QImage and QPainter
    QImage *map = new QImage(500, 500, QImage::Format_ARGB32);
    map->fill(QColor(255, 255, 255, 255));
    QPainter paint(map);
    paint.setRenderHint(QPainter::HighQualityAntialiasing);

    // Create Intensity map
    std::vector<int> record = disp_data[idx]; // Data
    for(int j = 1, c = record.size(); j < c; ++j) {
        int dm = 150 + record[j] * 100 / 255; // Vary the diameter

        QPen g_pen(QColor(0, 0, 0, 0));
        g_pen.setWidth(0);
        QRadialGradient grad(sensors[j-1].x, sensors[j-1].y, dm/2); // Create Gradient
        grad.setColorAt(0, QColor(0, 0, 0, record[j])); // Black, varying alpha
        grad.setColorAt(1, QColor(0, 0, 0, 0)); // Black, completely transparent
        QBrush g_brush(grad); // Gradient QBrush
        paint.setPen(g_pen);
        paint.setBrush(g_brush);
        paint.drawEllipse(sensors[j-1].x-dm/2, sensors[j-1].y-dm/2, dm, dm); // Draw circle
    }*/


}
