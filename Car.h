#include <iostream>
#include "iProfession.h"

using namespace std;
// abstract base class named Teacher publicly derived from the interface iProfession class.
class Car: public iVehicle{
    // private data member named "m_id"
    private:
        int m_speed;
    public:
        // constructor
        Truck(int m_speed){
            this->m_speed= m_speed;
        }
        // implement the act() public member function
        void move() const {
            // prints to the standard output stream the line 
         
    cout << "Move like a car" << endl;
        }
 };