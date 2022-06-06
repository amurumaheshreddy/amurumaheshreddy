// C++ program to illustrate the use of unique_ptr
#include <iostream>
#include <memory>
using namespace std;
class chegg{
public:
	void show()
	{
		cout << "chegg::show()" << endl;
	}
};
int main()
{
	unique_ptr<chegg> p1(new chegg);
	p1->show();
	// returns the memory address of p1
	cout << p1.get() << endl;
	// transfers ownership to p2
	unique_ptr<chegg> p2 = move(p1);
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;
	// transfers ownership to p3
	unique_ptr<chegg> p3 = move(p2);
	p3->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;
	cout << p3.get() << endl;
	return 0;
}
