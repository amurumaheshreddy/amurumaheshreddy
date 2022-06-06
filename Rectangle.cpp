#include<iostream>
using namespace std;
//2
class Rectangle {
   //attributes
   float length,width;
   public:
       //constructor
   Rectangle()
   {
       length=width =1;//default value
   }
   //method to find perimeter and return result
   float perimeter()
   {
       return 2*(length+width);  
   }
   //method to find area and return result
   float area()
   {
       return length*width;  
   }
   //getter methods
   float getLength()
   {
       return length;
   }
   float getWidth()
   {
   return width;  
   }
   //setter methods
   void setLength(float l)
   {
       //verifying
       if(0<l && l<20)
       length=l;
   }
   void setWidth(float w)
   {
       //verifying
       if(0<w && w<20)
       width=w;  
   }
   //method to display result
   void display()
   {
       cout<<"length = "<<length<<"; width = "<<width<<"; perimeter = "<<perimeter()<<"; area = "<<area()<<endl;  
   }
};
int main()
{
   //testing
   //creating object
   float L,W;
   Rectangle *r = new Rectangle();
   cout<<"a: ";
   r->display();
   r->setLength(5);
   r->setWidth(4);
   cout<<"b: ";
   r->display();
   r->setLength(1);
   r->setWidth(1);
   cout<<"c: ";
   r->display();   
   return 0;
}