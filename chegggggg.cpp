#include <iostream>
#include <string>
using namespace std;
int findItem(string addIn ,string addIns[],double addInPrices[],const int NUM_ITEMS,bool foundIt,double orderTotal);
int main()
{
// Declare variables.
string addIn; // Add-in ordered
const int NUM_ITEMS = 5; // Named constant
// Initialized array of add-ins
string addIns[] = {"Cream", "Cinnamon", "Chocolate", "Amaretto", "Whiskey"};
// Initialized array of add-in prices
double addInPrices[] = {.89, .25, .59, 1.50, 1.75};
bool foundIt = false; // Flag variable
int x; // Loop control variable
double orderTotal = 2.00; // All orders start with a 2.00 charge
// Get user input
int total;
total = findItem(addIn,addIns,addInPrices,NUM_ITEMS,foundIt,orderTotal);
cout << "\nTotal cost: " << total << endl;
return 0;
} // End of main()
int findItem(string addIn ,string addIns[],double addInPrices[],const int NUM_ITEMS,bool foundIt,double orderTotal){
    while(true)
    {
        cout << "Enter coffee add-in or XXX to quit: ";
       cin >> addIn;
        //check addIn is equal to XXX or not
        if(addIn == "XXX")
        break;
        //Iterate the loop
        for (int i = 0; i < NUM_ITEMS; ++i)
        {
            if(addIn == addIns[i])
            {
               //Display statement
                cout << "The price of" << addIns[i] << " is " << addInPrices[i] << "." << endl;
                foundIt = true;
                //calculate orderTotal
                orderTotal = orderTotal + addInPrices[i];
            }
        }
        if(foundIt == false){            //Display statement
            cout << "Sorry, we do not carry that." << endl;
            }
        }
        return orderTotal;
}