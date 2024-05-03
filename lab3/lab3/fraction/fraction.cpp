#include <iostream>
#include <cstring>
#include "fraction.h"

int stringToInt(const char* str) {
    int result = 0;
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        }
        else {
            return 0;
        }
        str++;
    }

    return result * sign;
}

int get_gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return get_gcd(b, a % b);
}

Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator){}

Fraction::Fraction(const char* str){
    Fraction f = castFromStr(str);
    numerator = f.numerator;
    denominator = f.denominator;
}

Fraction::Fraction(double d){
    Fraction f(d * 1000000, 1000000);
    int gcd = get_gcd(std::abs(f.numerator), std::abs(f.denominator));
    this->numerator = f.numerator / gcd;
    this->denominator = f.denominator / gcd;    
}

Fraction::Fraction(int d){
    this->numerator = d;
    this->denominator = 1;    
}

Fraction& Fraction::operator= (const Fraction& other) {
    if (&other != this) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Fraction& Fraction::operator= (const int& i) {
    numerator = i;
    denominator = 1;
    return *this;
}

Fraction& Fraction::operator= (const double& d) {
    Fraction f(d * 1000000, 1000000);
    int gcd = get_gcd(std::abs(f.numerator), std::abs(f.denominator));
    numerator = f.numerator / gcd;
    denominator = f.denominator / gcd; 
    return *this;
}

Fraction Fraction::operator+ (const Fraction& other) {
    return Fraction(this->numerator * other.denominator + other.numerator * this->denominator, this->denominator * other.denominator);
}

Fraction Fraction::operator+ (const int other) {
    return Fraction(this->numerator + this->denominator * other, this->denominator);
}

Fraction Fraction::operator+(const double& other) {
    Fraction f(other * 1000000, 1000000);
    Fraction s(this->numerator, this->denominator);

    int gcd = get_gcd(std::abs(f.numerator), std::abs(f.denominator));
    f.numerator /= gcd;
    f.denominator /= gcd;

    s = f + s;

    gcd = get_gcd(std::abs(s.numerator), std::abs(s.denominator));
    s.numerator /= gcd;
    s.denominator /= gcd;

    return s;
}

Fraction& Fraction::operator += (const Fraction& other) {
    if (&other != this) {
        this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
        this->denominator *= other.denominator;
    }
    return *this;
}

Fraction& Fraction::operator+= (const int other) {
    this->numerator = this->numerator + this->denominator * other;         
    return *this;
}

Fraction& Fraction::operator+=(const double& other) {
    Fraction f(other * 1000000, 1000000);
    Fraction s(this->numerator, this->denominator);

    int gcd = get_gcd(std::abs(f.numerator), std::abs(f.denominator));
    f.numerator /= gcd;
    f.denominator /= gcd;

    s = f + s;

    gcd = get_gcd(std::abs(s.numerator), std::abs(s.denominator));
    this->numerator = s.numerator / gcd;
    this->denominator = s.denominator / gcd;

    return *this;
}

Fraction& Fraction::operator- (const Fraction& other) {
    if (&other != this) {
        this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
        this->denominator *= other.denominator;
    }
    return *this;
}

Fraction& Fraction::operator- (const int other) {
    this->numerator = this->numerator - this->denominator * other;         
    return *this;
}

Fraction& Fraction::operator-(const double& other) {
    Fraction f(other * 1000000, 1000000);
    Fraction s(this->numerator, this->denominator);

    int gcd = get_gcd(std::abs(f.numerator), std::abs(f.denominator));
    f.numerator /= gcd;
    f.denominator /= gcd;

    s = f - s;

    gcd = get_gcd(std::abs(s.numerator), std::abs(s.denominator));
    s.numerator /= gcd;
    s.denominator /= gcd;

    return s;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    int gcd = get_gcd(f.numerator, f.denominator);
    if(!gcd)gcd = 1;
    os << f.numerator / gcd << '/' << f.denominator / gcd;
    return os;
}

std::istream& operator>> (std::istream& in, Fraction& f) {
    char str[100];
    in >> str;
    bool status = 0;
    for(int i = 0; i < strlen(str); i++){
        if (str[i] == '/')
            status = 1;
    }
    if (status)
        f = f.castFromStr(str);
    else{
        int i = stringToInt(str);
        in >> str;
        f = f.castFromStr(str);
        f += i;
    }
    return in;
}

Fraction operator+(int a, Fraction b) {
    return Fraction(a * b.denominator + b.numerator, b.denominator);
}

Fraction operator+(double a, Fraction b) {
    Fraction f(a * 1000000, 1000000);
    Fraction s(b.numerator, b.denominator);

    int gcd = get_gcd(std::abs(f.numerator), std::abs(f.denominator));
    f.numerator /= gcd;
    f.denominator /= gcd;

    s = f + s;

    gcd = get_gcd(std::abs(s.numerator), std::abs(s.denominator));
    s.numerator /= gcd;
    s.denominator /= gcd;

    return s;
}

Fraction Fraction::castFromStr(const char* str){
    char strWhole[100] = "";
    char strNum[100] = "";  
    char strDen[100] = "";
    int status = 0;
    int len = strlen(str);
    for(int i = len - 1; i >= 0; i--){
        if(str[i] == '/')status = 1;
        else if(str[i] == ' ')status = 2;
        else{
            switch (status)
            {
            case 0:
                strDen[strlen(strDen)] = str[i];
                break;
            case 1:
                strNum[strlen(strNum)] = str[i];
                break;
            case 2:
                strWhole[strlen(strWhole)] = str[i];
                break;
            }
        }
    }
    int whole = stringToInt(strrev(strWhole));
    int num = stringToInt(strrev(strNum));
    int den = stringToInt(strrev(strDen));
    if(status == 2)
        return Fraction(num + den * whole, den);
    if(status == 1)
        return Fraction(num, den); 
    return Fraction(den, 1);
}