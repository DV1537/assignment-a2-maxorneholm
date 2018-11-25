#include <iostream>
#include <fstream>
#include "Shape.cpp"
#include "Point.cpp"
#include "Line.cpp"
#include "Triangle.cpp"
#include "Polygon.cpp"

int main(){
 float kV = 0;
    float deltaY = 0;
    float deltaX = 0;
    float x = 0;
    int kCalc = 0;
    int xK = 0;
    int yK = 1;
    bool isLine = false;
    bool isPolygon = false;
    
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    std::ifstream file;
    file.open("shape.txt");

    //int *coordCounter = new int(0);
    int coordCounter = 0;

    if(file.is_open()){
        while(file >> x){
            coordCounter += 1;
        }
    }else{
        std::cout << "No file could be found." << std::endl;
    }

    float *coords = new float[coordCounter];
    float *xCoords = new float[coordCounter/2];
    float *yCoords = new float[coordCounter/2];
    float *kValue = new float[coordCounter/2]; 


    file.close();
    file.open("shape.txt");

    for(int i = 0; i < coordCounter; i++){
        file >> coords[i];
    }
    file.close();

    std::cout << "Raw input:" << std::endl;
    for(int i = 0; i < coordCounter; i++){
        std::cout << coords[i] << " ";
    }

    for(int i=0; i < coordCounter/2; i++){
        xCoords[i] = coords[xK];
        yCoords[i] = coords[yK];
        yK += 2;
        xK += 2;
    }

    std::cout << "\n\nCoordinates: \n";

    for(int i = 0; i < coordCounter/2; i++){
        std::cout << " (" << xCoords[i] << "," << yCoords[i] << ") ";
    }

    std::cout << "\n";

    // Calculate incline
   for(int i = 0; i < (coordCounter/2)-1; i++){
        deltaY = (yCoords[i+1] - yCoords[i]);
        deltaX = (xCoords[i+1] - xCoords[i]);
        kV = (deltaY/deltaX);
        kValue[i] = kV;
        kCalc++;
       // std::cout << kValue[i] << " ";
    }

    // line
    if(kCalc == 1){
        isLine = true;
    }

    // line
    if(kCalc > 1){
        for(int i=0; i < kCalc-1; i++){
            if(kValue[i] == kValue[i+1]){
                isLine = true;
            }else{
                isLine = false;
                isPolygon = true;
            }
        }
    }

    if(coordCounter/2 == 1){
        Point point(coords, coordCounter); 
        std::cout << "\nType: " << point.getType();
        std::cout << "\nArea: " << point.getArea();
        point.position();
    }

    //create new line object.
    if(isLine == true){
        Line line(coords, coordCounter);
        std::cout << "Type: " << line.getType() << '\n';
        std::cout << "Area: " << line.getArea() << '\n';
        line.position();
    }
    //create new triangle object.
    if(isPolygon == true && coordCounter/2 == 3 && isLine == false){
        Triangle triangle(coords, coordCounter);
        std::cout << "Type: " << triangle.getType() << '\n';
        std::cout << "Area: " << triangle.getArea() << '\n';
        std::cout << "Circumference: " << triangle.circumference() << '\n';
        triangle.position();
    }
    //create new polygon object.
    if(isPolygon == true && coordCounter/2 > 3 && isLine == false){
        Polygon polygon(coords, coordCounter);
        std::cout << "Type: " << polygon.getType() << '\n';
        std::cout << "Area: " << polygon.getArea() << '\n';
        std::cout << "Circumference: " << polygon.circumference() << '\n';
        polygon.position();
    }

    delete[] coords;
    delete[] xCoords;
    delete[] yCoords;
    delete[] kValue;

    coords = NULL;
    xCoords = NULL;
    yCoords = NULL;
    kValue = NULL;
    
    std::cout << '\n';
    getchar();
    return 0;
}