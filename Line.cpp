#include "Line.h"

Line::Line(){}

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
    float sumX = 0 , sumY = 0;
    for (int i=0; i < coordCounter/2 ;i++){
        sumX += xCoords[i];
        sumY += yCoords[i];
    }
    sumX /= coordCounter/2;
    sumY /= coordCounter/2;
    std::cout << "\nPosition: " << "(" << sumX << ", "  <<  sumY  <<  ")" << std::endl;
}
bool Line::isConvex(){
    return 1;
}
Line::~Line(){
    delete[] xCoords;
    delete[] yCoords;
    xCoords = NULL;
    yCoords = NULL;
}