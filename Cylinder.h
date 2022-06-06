//Cylinder.h
#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>
//include Circle.h file
#include "Circle.h"
using namespace std;
class Cylinder :public Circle
{
private:
   double height;
public:  
   //public member functions
   Cylinder(double radius,double height);
   void setheight(double h);
   double getheight();
   double area();
   double volume();
};
#endif CYLINDER_H