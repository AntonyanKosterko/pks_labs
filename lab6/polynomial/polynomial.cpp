#include "polynomial.h"
#include <map>
#include <algorithm>

// Конструктор, принимающий одночлен
Polynomial::Polynomial(Term t) {
    terms.push_back(t);
    degree = t.degree;
}

// Конструктор, принимающий строку, из которой строится одночлен
Polynomial::Polynomial(std::string s) {
    Term t(s);
    terms.push_back(t);
    degree = t.degree;
}

// Конструктор, принимающий вектор одночленов
Polynomial::Polynomial(std::vector<Term> v) {
    int m = 0;
    for (auto t : v) {
        terms.push_back(t);
        m = std::max(m, t.degree);
    }
    degree = m;
}

// Конструктор по умолчанию, создающий многочлен с одним нулевым одночленом
Polynomial::Polynomial() {
    Term t(0, 0);
    terms.push_back(t);
    degree = t.degree;
}

// Оператор присваивания
Polynomial& Polynomial::operator= (Polynomial p) {
    terms.clear();
    for (auto t : p.terms)
        terms.push_back(t);
    if (order_)
        std::sort(terms.begin(), terms.end());
    else
        std::sort(terms.rbegin(), terms.rend());
    degree = p.degree;
    return *this;
}

// Оператор сложения многочленов
Polynomial Polynomial::operator+(Polynomial other) {
    std::vector<Term> result_terms;
    sort(terms.rbegin(), terms.rend());
    sort(other.terms.rbegin(), other.terms.rend());
    int i = 0, j = 0;
    while (i < terms.size() && j < other.terms.size()) {
        if (terms[i] == other.terms[j]) {
            int new_coef = terms[i].coef + other.terms[j].coef;
            if (new_coef != 0) {
                result_terms.push_back(Term(new_coef, terms[i].degree));
            }
            i++;
            j++;
        } else if (terms[i] > other.terms[j]) {
            result_terms.push_back(terms[i]);
            i++;
        } else {
            result_terms.push_back(other.terms[j]);
            j++;
        }
    }

    while (i < terms.size()) {
        result_terms.push_back(terms[i]);
        i++;
    }

    while (j < other.terms.size()) {
        result_terms.push_back(other.terms[j]);
        j++;
    }
    if (order_)
        std::sort(result_terms.begin(), result_terms.end());
    else
        std::sort(result_terms.rbegin(), result_terms.rend());
    return Polynomial(result_terms);
}
    
// Оператор умножения многочленов
Polynomial Polynomial::operator*(Polynomial other) {
    std::vector<Term> result_terms;
    std::map<int, int> m;
    for (auto t : terms)
        for (auto f : other.terms)
            m[t.degree + f.degree] += t.coef * f.coef;
    for (auto p : m)
        result_terms.push_back(Term(p.second, p.first));
    if (order_)
        std::sort(result_terms.begin(), result_terms.end());
    else
        std::sort(result_terms.rbegin(), result_terms.rend());
    return Polynomial(result_terms);
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& os, Polynomial p) {
    if (p.order_)
        std::sort(p.terms.begin(), p.terms.end());
    else
        std::sort(p.terms.rbegin(), p.terms.rend());

    for (int i = 0; i < p.terms.size(); i++)
        if (i != p.terms.size() - 1)
            os << p.terms[i] << " + ";
        else
            os << p.terms[i] << " ";
    return os;
}

// Оператор ввода из потока
std::istream& operator>> (std::istream& in, Polynomial& p) {
    std::string str, s;
    int maxdegree = 0;
    while (s != "0") {
        in >> s;
        if (s == "0") break;
        str += s;
    }
    std::string cur = "";
    int i = 0;
    std::vector<int> opers;
    while (i < str.size()) {
        if (isdigit(str[i]) || str[i] == 'x') {
            for (int j = i; j <= str.size(); j++) {
                if (j == str.size()) {
                    i = j;
                    break;
                }
                if (str[j] == '+' || str[j] == '-') {
                    i = j;
                    break;
                }
                if (str[j] == ' ') continue;
                else
                    cur += str[j];
            }
            if (cur != "") {
                Term t(cur);
                if (t.coef) {
                    p.terms.push_back(t);
                    maxdegree = std::max(t.degree, maxdegree);
                }
                cur = "";
            }
        }
        if (str[i] == '-')
            opers.push_back(1);
        else
            opers.push_back(0);
        i++;
    }
    p.terms.erase(p.terms.begin());
    opers.pop_back();
    p.degree = maxdegree;
    
    if (opers.size() == p.terms.size()) {
        for (int i = 0; i < p.terms.size(); i++)
            if (opers[i])
                p.terms[i].coef *= -1;
    }
    else
        for (int i = 1; i < p.terms.size(); i++)
            if (opers[i - 1])
                p.terms[i].coef *= -1;
    
    return in;
}
