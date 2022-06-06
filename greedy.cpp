#include <iostream>
using namespace std;

// prototype declaration
void inputCelsiusTemp(double &celsius);// void function
double convertFahrenheit(double celsius); // returning value function

// MAIN FUNCTION
int main(){
double celsius; // declare variable
while(true){ // run infinite
        inputCelsiusTemp(celsius); // take input
       
       if(celsius==-999) // check if input is -999 stop and break
       break;
      
       double fahrenheit = convertFahrenheit(celsius); // calc temp in fahrenheit
       cout<<fahrenheit<<endl; // print fahrenheit
   
      if(fahrenheit < 78){ // check if < 78
            cout<<"Skiing day"<<endl;  
       }else{
           cout<<"Swimming day"<<endl;
       }
}
cout<<"Good Bye"<<endl; // print message
return 0;
}

// FUNCTION DEFINITION
// take input
void inputCelsiusTemp(double &celsius){
   cout<<"Enter temperature in celsius: ";
   cin >> celsius;
}
// convert and return
double convertFahrenheit(double celsius){
   double fahrenheit = (celsius * 9.0) / 5.0 + 32;
   return fahrenheit;
}