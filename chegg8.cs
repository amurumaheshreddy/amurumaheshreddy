// C++ program to implement
// Hierarchical Inheritance
#include<iostream>
using namespace std;

// base class
class Values
{
public:
	Values()
	{
	cout << "This is a Vehicle\n";
	}
};


// first sub class
class Ascending: public Values
{

};

// second sub class
class Descending: public Values
{
	
};

// main function
int main()
{
	// Creating object of sub class will
	// invoke the constructor of base class.
	Ascending obj1;
	Descending obj2;
	return 0;
}
