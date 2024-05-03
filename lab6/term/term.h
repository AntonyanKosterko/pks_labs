#ifndef TERM_H
#define TERM_H

#include <string>
#include <iostream>

class Term {
public:
    int coef;
    int degree;
    Term();
    Term(int coef, int degree);
    Term(std::string str);

    Term& operator= (const Term& t);
    bool operator< (const Term& t);
    bool operator> (const Term& t);
    bool operator== (const Term& t);
    
    friend std::ostream& operator<<(std::ostream& os, const Term& t);
    friend std::istream& operator>> (std::istream& in, Term& t);
    friend Term operator+(Term a, Term b);
    friend class Polynomial;
};

Term operator+(Term a, Term b);
std::ostream& operator<<(std::ostream& os, const Term& t);
std::istream& operator>> (std::istream& in, Term& t);
#endif
