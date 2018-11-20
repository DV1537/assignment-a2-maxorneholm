#include "Point.h"
#include <iostream>

void Point::getType(){
    type = "Point";
    std::cout << "Type: " << type << std::endl;
}

void Point::position(float* xCoords, float* yCoords){
    std::cout << "\nCenter coordinates: " << "(" << xCoords[0] << ", " << yCoords[0] << ")" << std::endl;
}

void Point::getArea(float* xCoords, float* yCoords){
    area = -1;
    std::cout << "Area: " << area << " l.e";
}

void Point::circumference(){}