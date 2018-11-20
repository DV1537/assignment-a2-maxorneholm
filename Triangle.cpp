#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <string>

void Triangle::getType(){
    type = "Triangle";
    std::cout << "Type: " << type;
}

void Triangle::getArea(float* xCoords, float* yCoords){
    // Get the length from A -> B
    float xAtoB = pow(xCoords[1]-xCoords[0],2);
    float yAtoB = pow(yCoords[1]-yCoords[0],2);
    distanceAtoB = sqrt(xAtoB+yAtoB);
    // Get the length from A -> C
    float xAtoC = pow(xCoords[2]-xCoords[0],2);
    float yAtoC = pow(yCoords[2]-yCoords[0],2);
    distanceAtoC = sqrt(xAtoC+yAtoC); 
    // Get the length from B -> C
    float xBtoC = pow(xCoords[2]-xCoords[1],2);
    float yBtoC = pow(yCoords[2]-yCoords[1],2);
    distanceBtoC = sqrt(xBtoC+yBtoC);
/*
    std::cout << '\n' << "A to B: " << distanceAtoB;
    std::cout << '\n' << "A to C: " << distanceAtoC;
    std::cout << '\n' << "B to C: " << distanceBtoC;
*/

    if(distanceAtoB > distanceAtoC && distanceAtoB > distanceBtoC){
    hypo = distanceAtoB;
    base = distanceAtoC;
    height = distanceBtoC;
    }
    if(distanceAtoC > distanceAtoB && distanceAtoC > distanceBtoC){
    hypo = distanceAtoC;
    base = distanceAtoB;
    height = distanceBtoC;
    }
    if(distanceBtoC > distanceAtoB && distanceBtoC > distanceAtoC){
    hypo = distanceBtoC;
    base = distanceAtoB;
    height = distanceAtoC;
    }

    area = (base*height)/2.0f;
    std::cout << '\n' << "Area: " << area << " l.e";
}

void Triangle::circumference(){
    circum = distanceAtoB + distanceAtoC + distanceBtoC;
    std::cout << "\nCircumference: " << circum << " l.e";
}

void Triangle::position(float* xCoords, float* yCoords){

    for(int i=0; i < 3; i++){
        sumX += xCoords[i];
        sumY += yCoords[i];
    }

    std::cout << "\nCenter coordinates: " << "(" << sumX/3 << ", " << sumY/3 << ")" << std::endl;
}