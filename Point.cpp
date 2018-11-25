#include "Point.h"
#include <iostream>

Point::Point(){}

Point::Point(float* coords, int coordCounter){
        this->xCoords = new float[coordCounter/2];
        this->yCoords = new float[coordCounter/2];

        int yK = 1;
        int xK = 0;

        for(int i=0; i < coordCounter/2; i++){
            this->xCoords[i] = coords[xK];
            this->yCoords[i] = coords[yK];
            yK += 2;
            xK += 2;
        }
}

std::string Point::getType(){
    return type;
}

float Point::getArea(){
    return area;
}
float Point::circumference(){
    return 0;
}
void Point::position(){
    std::cout << "\nPosition: (" << xCoords[0] << ", " << yCoords[0] << ")" << std::endl;
}
bool Point::isConvex(){
    return 1;
}

Point::~Point(){
    delete[] xCoords;
    delete[] yCoords;
    xCoords = NULL;
    yCoords = NULL;
}