//Cylinder.cpp
#include "Cylinder.h"
//constructor that takes radius and height
//pass the radius to the base class circle constructor
Cylinder::Cylinder(double radius,double height) :Circle(radius)
{
   this->height=height;
}
void Cylinder::setheight(double h)
{
   height=h;
}
double Cylinder::getheight()
{
   return height;
}
//calculate area ,2*PI*r^2
double Cylinder::area()
{
   return 2.0*PI*getradius()*(getradius()+height);
}
//calculate volume ,PI*r^2*h
double Cylinder::volume()
{
   return PI*getradius()*getradius()*height;
}