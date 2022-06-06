#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction()
{
this->numerator = 0;
this->denominator = 0;

}

Fraction::Fraction(int numerator, int denominator)
{
this->numerator = numerator;
this->denominator = denominator;
}

int gcd(int numerator, int denominator)
{
if (numerator % denominator == 0) return denominator;
return gcd(denominator, numerator % denominator);
}

void Fraction::setNumerator(int numerator)
{
this->numerator = numerator;
}

void Fraction::setDenominator(int enterDenom)
{
this->denominator = enterDenom;
}

int Fraction::getNumerator()
{
return this->numerator;
}

int Fraction::getDenominator()
{
return this->denominator;
}

void Fraction::Initial()
{
cout << "The Fraction in its initial form:" << numerator << "/" << denominator << endl;
cout << "The Fraction Real number form:" << (double)numerator / (double)denominator << endl;

}

void Fraction::Reduced()
{
if (numerator < denominator)
{
int t = gcd(numerator, denominator);
numerator = numerator / t;
denominator = denominator / t;
cout << "The Fraction reduced to its lowest terms:" << numerator << "/" << denominator << endl;
}
else
{
if (numerator > denominator)
{
int t = gcd(numerator, denominator);
numerator = numerator / t;
denominator = denominator / t;
cout << "The Fraction reduced to its lowest terms:" << numerator << "/" << denominator << endl;
}
else
{
if (numerator % denominator == 0)
cout << "The Fraction reduced to its lowest terms:" << numerator << endl;
}
}

}

void Fraction::Mixed()
{
if (numerator % denominator == 0)
{
cout << "The Fraction in Mixed number form:" << numerator << endl;
}
else
{
int t = gcd(numerator, denominator);
numerator = numerator / t;
denominator = denominator / t;
int w = numerator / denominator;
numerator = numerator - denominator * w;
cout << "The Fraction in Mixed number form:" << w << " " << numerator << "/" << denominator << endl;
  
}
}


Fraction Fraction::operator+(Fraction obj)
{
Fraction result;
result.numerator = (obj.numerator * denominator) + (obj.denominator * numerator);
result.denominator = obj.denominator * denominator;
result.Reduced();
return result;
}

Fraction Fraction::operator-(Fraction sub)
{
Fraction result;
result.numerator = (sub.denominator * numerator) - (sub.numerator * denominator);
result.denominator = sub.denominator * denominator;
result.Reduced();
return result;
}

Fraction Fraction::operator*(Fraction mult)
{
Fraction result;
result.numerator = mult.numerator * numerator;
result.denominator = mult.denominator * denominator;
result.Reduced();
return result;
}

Fraction Fraction::operator/(Fraction divi)
{
Fraction result;
result.numerator = divi.denominator * numerator;
result.denominator = divi.numerator * denominator;
result.Reduced();
return result;
}