#include "Polygon.h"
#include <iostream>

Polygon::Polygon(){}

Polygon::Polygon(float* coords, int coordCounter){
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

std::string Polygon::getType(){
    return type;
}

float Polygon::getArea(){
    
    float current = 0;
    float last = 0;
    int lastCounter = 0;

    //Get all except last.
    for(int i = 0; i < (coordCounter/2)-1; i++){
        current = ((xCoords[i] * yCoords[i+1]) - (yCoords[i] * xCoords[i+1]));
        area += current;
        lastCounter++;
    }
    //Get the last -> first.
    last = ((xCoords[lastCounter] * yCoords[0]) - (yCoords[lastCounter] * xCoords[0]));
    area += last;

    area = abs(area);
    area = area/2;

    return area;
}

float Polygon::circumference(){
    //Get the sides lengths.
    int lastCounter = 0;
    int total = 0;
    float x = 0, y = 0;

    for(int i = 0; i < (coordCounter/2)-1; i++){
        x = pow(xCoords[i+1]-xCoords[i],2);
        y = pow(yCoords[i+1]-yCoords[i],2);
        total += sqrt(x+y);
        lastCounter++;
    }

    //Get the last sides length.
    float lastX = pow(xCoords[lastCounter]-xCoords[0],2);
    float lastY = pow(yCoords[lastCounter]-yCoords[0],2);
    total += sqrt(lastX+lastY);

    return total;
}

void Polygon::position(){
    float x = 0, y = 0;
    float sumX = 0, sumY = 0;
    for (int i = 0; i < (coordCounter/2); i++){
			x += xCoords[i];
			y += yCoords[i];
		}
		x /= (coordCounter/2);
		y /= (coordCounter/2);
		sumX = x;
        sumY = y;

    std::cout << "Position: (" << sumX << ", " << sumY << ")\n";
}
bool Polygon::isConvex(){return 0;}