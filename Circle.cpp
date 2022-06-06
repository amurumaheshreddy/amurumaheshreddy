/* The Circle class (All source codes in one file) (CircleAIO.cpp) */
#include <iostream>    // using IO functions
#include <string>      // using string
using namespace std;
 
class BaseCircle {
protected:
   double radius;      // Data member (Variable)
public:
   // Constructor with default values for data members
   BaseCircle(double r = 1) {
      radius = r;
   }
 
   double GetRadius() {  // Member function (Getter)
      return radius;
   }
   double SetRadius(double r)
   {
      if(r>0)
      radius=r;
      else
      radius=0;
   }

};   // need to end the class declaration with a semi-colon
 
// Test driver function
int main() {
   // Construct a Circle instance
   BaseCircle obj;
   cout << "Radius=" << obj.GetRadius()<< endl;

   // Construct another Circle instance
   obj.SetRadius(4.5);
   cout << "Radius=" << obj.GetRadius()<< endl;
   obj.SetRadius(-4.5);
   // Construct a Circle instance using default no-arg constructor
   cout << "Radius=" << obj.GetRadius()<< endl;
   return 0;
}