#include <iostream>
#include <fstream>
#include <string>
#include "Shape.cpp"
#include "Triangle.cpp"

int main(){
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    std::ifstream file;
    file.open("shape.txt");

    int *coordCounter = new int(0);
    float x = 0;

    if(file.is_open()){
        while(file >> x){
            *coordCounter += 1;
        }
    }else{
        std::cout << "No file could be found." << std::endl;
    }

    float *coords = new float[*coordCounter];
    float *xCoords = new float[*coordCounter/2];
    float *yCoords = new float[*coordCounter/2];

    file.close();
    file.open("shape.txt");

    for(int i = 0; i < *coordCounter; i++){
        file >> coords[i];
    }
    file.close();
    std::cout << "Raw input:" << std::endl;
    for(int i = 0; i < *coordCounter; i++){
        std::cout << coords[i] << " ";
    }

    int xK = 0;
    int yK = 1;
    for(int i=0; i < *coordCounter/2; i++){
        xCoords[i] = coords[xK];
        yCoords[i] = coords[yK];
        yK += 2;
        xK += 2;
    }

    std::cout << "\n\nCoordinates: \n";

    for(int i = 0; i < *coordCounter/2; i++){
        std::cout << " (" << xCoords[i] << "," << yCoords[i] << ") ";
    }

    std::cout << "\n\n";

    if(*coordCounter/2 == 1){
        //Point b;
        //a.getType();
    }

    if(*coordCounter/2 == 3){
        Triangle a;
        a.getType();
        a.getArea(xCoords, yCoords);
        a.circumference();
        a.position(xCoords, yCoords);
    }


    getchar();
    return 0;
}