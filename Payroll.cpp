#include "Paycheck.h"
#include<iostream>
using namespace std;
const int N = 3;
// driver function
int main()
{
    // variables
    string name;
    double grossPay, taxRate;
    int startingCheckNumber;

    // create an array of N Paycheck objects
    Paycheck checks[N];

    // set up details of the Paycheck objects by prompting the user
    for (int i = 0; i < N; i++)
    {
        cout << "For Employee#" << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter gross pay: ";
        cin >> grossPay;
        cout << "Enter tax rate: ";
        cin >> taxRate;
        cout << "\n";

        // set up the details of the ith object
        checks[i] = Paycheck(name, grossPay, taxRate);
    }

    cout << "\nStart? ";
    cin >> startingCheckNumber;

    // set the checkNumber for the objects
    Paycheck::setCheckNumber(startingCheckNumber);

    // print details of all checks by calling the printCheck() function
    for (int i = 0; i < N; i++)
        checks[i].printCheck();

    // print the next check number
    cout << "Next Check: " << Paycheck::getCheckNumber() << "\n";

    return 0;
}