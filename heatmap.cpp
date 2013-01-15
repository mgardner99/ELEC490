#include "heatmap.h"

void HeatMap::genMap(vector<DataPoint> vec){
    //int min = 0;
    int max = 0;
    float data[img->size().width()][img->size().height()];

    for(int i = 0; i < img->size().width(); i++){
        for (int j = 0; j< img->size().height(); j++){
            for(int k = 0; k < vec.size(); k++){ //vector loop
                float dist = vec[k].getDist(i,j);
                data[i][j] = dist;

                if(dist > max)
                    max = dist;
            }
            //QColor c((i/(float)img->size().width()*255),(i/(float)img->size().width()*255),(i/(float)img->size().width()*255));
            //img->setPixel(i,j,c.rgb());
        }
    }

    for(int i = 0; i < img->size().width(); i++){
        for (int j = 0; j< img->size().height(); j++){
            QColor c(data[i][j]/(float)max*255,data[i][j]/(float)max*255,data[i][j]/(float)max*255);
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
