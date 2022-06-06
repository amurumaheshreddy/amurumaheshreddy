//include the required header file

#include <iostream>

#include <iomanip>

using namespace std;

// definition of "Tips" Class

class Tips

{

//access specifier

private:

//declare the variable

double taxRate;

//access specifier

  public:

// constructor

Tips(double rate = .065)

{

//check the condition

if (rate >= 0)

//set the value

taxRate = rate;

//otherwise

else

//set the value

taxRate = .065;

}

//declare the member function

double computeTip(double, double);

};

//definition of "computeTip" function

double Tips::computeTip(double total_Bill, double tip_Rate)

{

/*declare and Compute the values for the variables "meal_Cost" and "tip_Amount"*/

double meal_Cost = total_Bill / (1 + taxRate);

double tip_Amount = meal_Cost * tip_Rate;

//return the value

return tip_Amount;

}

//main method definition

int main()

{

//declare the required variables

double total_Bill, taxRate, tip_Rate, tip_Amt;

char   ch;

//set the decimal point

cout << fixed << showpoint << setprecision(2);

// get the input and validate the tax rate

cout << "\nTax percentage for this location: ";

cin  >> taxRate;

//check the condition

while (taxRate < 0)

{

//get the input from the user

cout << "Tip percentage cannot be less than 0. Please re-enter tip percentage: ";

cin >> taxRate;

}

//convert the input from percentage to decimal

taxRate = taxRate / 100;

// create a "Tips" object

Tips tip(taxRate);

// Begin main processing loop

do

{

cout << "\n************* Tip Helper *********** \n";

/* get the input and validate the total bill amount*/

cout << "\nEnter total bill amount: ";

cin  >> total_Bill;

//check the condition

while (total_Bill < 0)

{

//get the input from the user

cout << "Total cannot be less than 0. Please re-enter total bill amount: ";

cin  >> total_Bill;

}

/* get the input and validate the desired tip percentage*/

cout << "Enter desired tip percentage ";

cin  >> tip_Rate;

//check the condition

while (tip_Rate < 0)

{

//get the input from the user

cout << "Tip percentage cannot be less than 0. Please re-enter tip percentage: ";

cin  >> tip_Rate;

}

//convert the input from percentage to decimal

tip_Rate = tip_Rate / 100;

// Call the "computeTip" function

tip_Amt = tip.computeTip(total_Bill, tip_Rate);

// Display the output

cout << "\nThe tip should be $ " << tip_Amt << endl << endl;

// get the user response

cout << "Compute another tip (y/n)? ";

cin  >> ch;

} while (toupper(ch) == 'Y');

//return statement

return 0;

}