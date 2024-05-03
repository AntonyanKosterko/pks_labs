#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
public:
    int numerator, denominator;

    Fraction(int numerator = 0, int denominator = 0);
    Fraction castFromStr(const char* str);
    Fraction(const char* str);
    Fraction(double d);
    Fraction(int d);

    Fraction& operator= (const Fraction& other);
    Fraction& operator= (const int& i);
    Fraction& operator= (const double& d);

    Fraction operator+ (const Fraction& other);
    Fraction operator+ (const int other);
    Fraction operator+(const double& other);

    Fraction& operator += (const Fraction& other);
    Fraction& operator+= (const int other);
    Fraction& operator+=(const double& other);

    Fraction& operator- (const Fraction& other);
    Fraction& operator- (const int other);
    Fraction& operator-(const double& other);
};

std::ostream& operator<<(std::ostream& os, const Fraction& f);
std::istream& operator>> (std::istream& in, Fraction& f);
Fraction operator+(int a, Fraction b);
Fraction operator+(double a, Fraction b);
#endif
