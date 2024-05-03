#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include <iostream>
#include <vector>
#include "../term/term.h"


class Polynomial{
protected:
    bool order_;
public:
    std::vector<Term> terms;
    int degree;
    Polynomial(Term t);
    Polynomial(std::string s);
    Polynomial(std::vector<Term> v);
    Polynomial();
    Polynomial& operator= (Polynomial p);
    Polynomial operator+(Polynomial other);    
    Polynomial operator*(Polynomial other);
    friend std::istream& operator>> (std::istream& in, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& os, Polynomial p);
};
std::istream& operator>> (std::istream& in, Polynomial& p);
std::ostream& operator<<(std::ostream& os, Polynomial p);
#endif
