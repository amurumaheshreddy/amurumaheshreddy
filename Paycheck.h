#ifndef PAYCHECK_H
#define PAYCHECK_H
#include <iostream>
#include <iomanip>
using namespace std;
class Paycheck
{
    string name;
    double grosspay;
    double taxrate;
    static int checkNumber;

public:
    // default constructor
    Paycheck();
    // parameterized constructor
    Paycheck(string n, double g, double t);

    // function to print a check
    void printCheck();

    // function to set the checkNumber
    static void setCheckNumber(int num);

    // function to get the checkNumber
    static int getCheckNumber();
};

