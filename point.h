#include <iostream>
#include<math.h>
using namespace std;

class point{
    private:
    // Data members x and y
    float x;
    float y; 

    public:
    point();// Default Constructor, sets X = Y = 0
    point(float, float);// Constructor. Initializes both X and Y.
    void setX(float);// Set X value
    void setY(float);// Set Y value
    float getX();// Get X value
    float getY();// Get Y value
    void DisplayPoint();// Display point as (X , Y)
    float distance(point);// distance between current point object and another point p
};

point::point(){
    x=0;
    y=0;
}
point::point(float xcoordinate, float ycoordinate){
    x=xcoordinate;
    y=ycoordinate;
}
void point::setX(float xcoordinate){
    x=xcoordinate;
}
void point::setY(float ycoordinate){
    y=ycoordinate;
}
float point::getX(){
    return x;
}
float point::getY(){
    return y;
}
void point::DisplayPoint(){
    cout<<"( "<<x<<", "<<y<<" )\n";
}
float point::distance(point q){
    float Xsqr=pow(x-q.x,2);
    float Ysqr=pow(y-q.y,2);
    return pow(Xsqr+Ysqr,0.5);
}