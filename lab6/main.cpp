#include <bits/stdc++.h>
#include "polynomial/polynomial.h"
#include "term/term.h"

void demo(){
    std::string s = "2x^5";
    Term t(s);
    Term sumTerm("4x^5");
    std::cout << t + sumTerm << '\n';
    Term t1("4x^3");
    Term t2("x");
    Term t3("3");
    Term t4("8x^5");
    Polynomial p1(t1);
    p1 = p1 + t2 + t;
    std::vector<Term> v = {t3, t4};
    Polynomial p2(v);
    
    std::cout << p1 << '\n';
    std::cout << p2 << '\n';
    std::cout << p1 + p2 << '\n';
    std::cout << p1 * p2 << '\n';
}

void interactive(){
    std::string s;
    std::cin >> s;
    Term t(s);
    Term t1("4x^3");
    Term t2("x");
    Term t3("4");
    Term t4("4x^5");
    Polynomial p1(t1);
    p1 = p1 + t2 + t;
    std::vector<Term> v = {t3, t4};
    Polynomial p2(v);
    Polynomial p3;
    std::cin >> p3;
    std::cout << "your polynomial " << p3 << '\n';
    std::cout << p1 << '\n';
    std::cout << p2 << '\n';
    std::cout << p1 + p2 << '\n';
    std::cout << p1 * p2 << '\n';
}

int main() {
    setlocale(LC_ALL, "Russian");
    int status;
    std::string message = "0 - demo\n1 - interactive\n";
    std::cout << message;
    
    while(true){
        std::cin >> status;
        switch (status)
        {
        case 0:
            demo();
            return 0;
        case 1:
            interactive();
            return 0;
        default:
            std::cout << message;
        }
    }
    return 0;
}
