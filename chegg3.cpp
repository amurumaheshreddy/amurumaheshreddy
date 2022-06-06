/**
Test c ++ program for Circle and
cylinder classes methods.
*/
//main.c
//include header files
#include<iostream>
//include custom header files
#include "Circle.h"
#include "Cylinder.h"
using namespace std;
//main function
int main()
{
   //create Circle object,c1
   Circle c1(10);
   cout<<"Circle cir1: radius= "
       <<c1.getradius()<<endl;
   cout<<"area of cir1= "
       <<c1.area()<<endl;

   //create Circle object,c2
   Circle c2;
   c2.setradius(12);
   cout<<"Circle cir2: radius= "
       <<c2.getradius()<<endl;
   cout<<"area of cir2= "
       <<c2.area()<<endl;

   //create a Cylinder object
   Cylinder cylinder(20,30);

   cout<<"Cylinder cyl1: radius ="
       <<cylinder.getradius()
       <<" height = "
       <<cylinder.getheight()<<endl;

   cout<<"area of cyl1 = "
       <<cylinder.area()<<endl;

   cout<<"volume of cyl1 = "
       <<cylinder.volume()<<endl;


   //create a Cylinder object
   Cylinder cylinder2(40,50);

   cout<<"Cylinder cyl1: radius ="
       <<cylinder2.getradius()
       <<" height = "
       <<cylinder2.getheight()<<endl;

   cout<<"area of cyl1 = "
       <<cylinder2.area()<<endl;

   cout<<"volume of cyl1 = "
       <<cylinder2.volume()<<endl;


   system("pause");
   return 0;
}