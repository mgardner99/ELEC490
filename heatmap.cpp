#include "heatmap.h"

void HeatMap::genMap(vector<DataPoint> vec){
    float max = 0;
    float data[img->size().width()][img->size().height()];

    //init the data array
    for(int i =0; i < img->size().width(); i++){
        for (int j = 0; j < img->size().height(); j++){
            data[i][j] = 0;
        }
    }

    float radius[vec.size()];

    for (int i = 0; i < vec.size(); i++){
        radius[i] = RADC*vec[i].getVal();
        //R = Px * C
    }

    //calc all the pixel data values
    for(int i = 0; i < img->size().width(); i++){
        for (int j = 0; j< img->size().height(); j++){
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
    for(int i = 0; i < img->size().width(); i++){
        for (int j = 0; j< img->size().height(); j++){
            QColor c(255-data[i][j]/max*255,255-data[i][j]/max*255,255-data[i][j]/max*255);
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
