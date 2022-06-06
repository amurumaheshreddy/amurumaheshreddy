#ifndef FRACTION_H
#define FRACTION_H

#include <string>
using namespace std;

class Fraction {

private:
int numerator, denominator;

public:
Fraction();
Fraction(int, int);
int getNumerator(void);
int getDenominator(void);
void setNumerator(int);
void setDenominator(int);
void Initial();
void Reduced();
void Mixed();
Fraction operator+(Fraction);
Fraction operator-(Fraction);
Fraction operator*(Fraction);
Fraction operator/(Fraction);
};
#endif