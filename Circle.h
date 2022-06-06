#ifndef CIRCLE_H
#define CIRCLE_H
//circle class defintion
class Circle
{
private:
   double radius;
public:
   //public data members
   Circle();
   Circle(double r);
   void setradius(double r);
   double getradius();
   double area();
};
//set PI constance
static const double PI=3.1415;
#endif CIRCLE_H