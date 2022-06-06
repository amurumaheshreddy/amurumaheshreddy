#include <iostream>
#include <cmath>

/**
 * Starter code for assignment 24.
 */

#define NUM 7
#define PI 3.14

using namespace std;

class Shape {
  public:
    /** Returns the name of the class. */
    virtual const char* name() const = 0;
    /** Prints the area or surface area, and volume of the object. */
    virtual void printDetails() const = 0;
    /**
     * Prompts the user to enter a radius, side, and/or height
     * of the object and set the appropriate data member(s).
     */
    virtual void inputData() = 0;
    /** Calculates and returns the area or surface area of the object. */
    virtual double area() const = 0;
    /** Calculates and returns the volume of the object. */
    virtual double volume() const {
      return 0.0;
    }     
};   

class Circle : public Shape {
  public:
    // Parameter syntax "datatype variable = value" will give
    // a default value for the variable if one is not supplied as an argument.
    // This constructor can be called with no arguments or one argument
    // Example: shapeArray[0] = new Circle(); 
    // Example: Circle circle1 = new Circle(10);
    Circle (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Circle";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s area = " << area() << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
    }
    
    double area() const {
      return PI * radius * radius;
    }
   
  protected:    
    double radius;
};

class Sphere : public Shape {
  public:
    
    Sphere (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Sphere";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s surface area = " << area() << endl;
       cout << "The " << name() << "'s volume = " << ((4*PI * radius * radius*radius)/3) << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
    }
    
    double area() const {
      return 4*PI * radius * radius;
    }
   
  protected:    
    double radius;
};
class Cylinder : public Shape {
  public:
    
   Cylinder (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Cylinder";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s surface area = " << area() << endl;
      cout << "The " << name() << "'s volume = " << (PI * radius * radius*height) << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
      cout << "Enter the " << name() << "'s height: ";
      cin>>height;
    }
    
    double area() const {
      return 2*PI*radius*height+2*PI*radius*radius;
    }
   
  protected:    
    double radius;
    double height;
};
class Square : public Shape {
  public:
    
    Square (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Square";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s area = " << area() << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s side: ";
      cin >> radius;
    }
    
    double area() const {
      return  radius * radius;
    }
   
  protected:    
    double radius;
};
class  Cube : public Shape {
  public:
    
     Cube (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Cube";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s surface area = " << area() << endl;
      cout << "The " << name() << "'s volume = " << (radius*radius * radius) << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s side: ";
      cin >> radius;
    }
    
    double area() const {
      return 6* radius * radius;
    }
   
  protected:    
    double radius;
};
class Triangle : public Shape {
  public:
    
    Triangle (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Triangle";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s area = " << area() << endl;
      
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s side: ";
      cin >> radius;
    }
    
    double area() const {
      return  radius * radius*sqrt(3)/4;
    }
   
  protected:    
    double radius;
};
class Tetrahedron : public Shape {
  public:
    
    Tetrahedron(double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Tetrahedron";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s surface area = " << area() << endl;
       cout << "The " << name() << "'s volume = " << (radius*radius * radius)*sqrt(2)/12 << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s side: ";
      cin >> radius;
    }
    
    double area() const {
      return  radius * radius*sqrt(3);
    }
   
  protected:    
    double radius;
};
/** Add the remaining classes here. */

int displayMenu(Shape *[]);

int main() {
   
  Shape *shapeArray[NUM];
  shapeArray[0] = new Circle();

 // Uncomment the line below when you have completed its corresponding classs for that shape.
 // The shape will be added to the array and the corresponding menu option will be shown.
  shapeArray[1] = new Sphere();
  shapeArray[2] = new Cylinder();
  shapeArray[3] = new Square();
  shapeArray[4] = new Cube();
  shapeArray[5] = new Triangle();
 shapeArray[6] = new Tetrahedron();

  int choice = displayMenu(shapeArray);
  while (choice >= 0 && choice <= 6) {
    shapeArray[choice]->inputData();
    shapeArray[choice]->printDetails();
    cout << endl;
    choice = displayMenu(shapeArray);
  }
  return 0;
}

/**
 * Displays the menu for which shape to perform calculations.
 *
 * @param shapeArrayParam array of shapes that this program supports
 * @return the choice from the user
 */
int displayMenu(Shape *shapeArrayParam[]) {
  int choice=0 ;
  cout << "Select an object from the menu (enter 7 to quit)." << endl;
  for (int i = 0; i < NUM; i++) {
    cout << '\t' << i << ". " << shapeArrayParam[i]->name() << endl;
  }
  cin >> choice;
  return choice;
}