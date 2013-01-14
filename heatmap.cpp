#include "heatmap.h"

void HeatMap::genMap(vector<DataPoint> vec){
    for(int i = 0; i < img->size().width(); i++){
        for (int j = 0; j< img->size().height(); j++){
            QColor c((i/(float)img->size().width()*255),(i/(float)img->size().width()*255),(i/(float)img->size().width()*255));
            img->setPixel(i,j,c.rgb());
        }
    }
}

HeatMap::HeatMap(QSize size, QImage::Format form){
    img = new QImage(size,form);

}

QImage HeatMap::getImg(){
    return *img;
}
