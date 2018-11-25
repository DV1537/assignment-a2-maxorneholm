#include "Line.h"

Line::Line(){
//def
}

Line::Line(float* coords, int coordCounter){
        this->xCoords = new float[coordCounter/2];
        this->yCoords = new float[coordCounter/2];
        this->coordCounter = coordCounter;
        int yK = 1;
        int xK = 0;

        for(int i=0; i < coordCounter/2; i++){
            this->xCoords[i] = coords[xK];
            this->yCoords[i] = coords[yK];
            yK += 2;
            xK += 2;
        }
}

std::string Line::getType(){
    return type;
}

float Line::getArea(){
    return area;
}

float Line::circumference(){
    return circum;
}

void Line::position(){
    float xSum = 0 , ySum = 0;
    for (int i=0; i < coordCounter/2 ;i++){
        xSum += xCoords[i];
        ySum += yCoords[i];
    }
    xSum /= coordCounter/2;
    ySum /= coordCounter/2;
    std::cout << "Center coordinates: " << xSum << ","  <<  ySum  <<  ".";
}
bool Line::isConvex(){return 0;}