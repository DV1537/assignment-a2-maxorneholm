#include "Triangle.h"
#include <cmath>
#include <iostream>
Triangle::Triangle(){}

Triangle::Triangle(float* coords, int coordCounter){
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

std::string Triangle::getType(){
    return type;
}

float Triangle::getArea(){

   /* float hypo = 0;
    float base = 0;
    float height = 0;
    float circumFormula = 0;
*/
    // Get the length A -> B
    float xAtoB = pow(xCoords[1]-xCoords[0],2);
    float yAtoB = pow(yCoords[1]-yCoords[0],2);
     distanceAtoB = sqrt(xAtoB+yAtoB);
    // Get the length A -> C
    float xAtoC = pow(xCoords[2]-xCoords[0],2);
    float yAtoC = pow(yCoords[2]-yCoords[0],2);
     distanceAtoC = sqrt(xAtoC+yAtoC); 
    // Get the length B -> C
    float xBtoC = pow(xCoords[2]-xCoords[1],2);
    float yBtoC = pow(yCoords[2]-yCoords[1],2);
     distanceBtoC = sqrt(xBtoC+yBtoC);

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

    circumFormula = (distanceAtoB + distanceAtoC + distanceBtoC)/2;
    area = sqrt(circumFormula*(circumFormula-distanceAtoB)*(circumFormula-distanceBtoC)*(circumFormula-distanceAtoC));
    return area;
}

float Triangle::circumference(){
    circum = distanceAtoB + distanceAtoC + distanceBtoC;
    return circum;
}
void Triangle::position(){
    float sumX = 0, sumY = 0;
    for(int i=0; i < 3; i++){
        sumX += xCoords[i];
        sumY += yCoords[i];
    }
    sumX /= 3;
    sumY /= 3;

    std::cout << "Center coordinates: " << "(" << sumX << ", " << sumY << ")" << std::endl;
}
bool Triangle::isConvex(){return 0;}