#include "term.h"

// Функция для преобразования строки в целое число
int stringToInt(std::string str) {
    int result = 0;
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        str = str.substr(1); 
    }

    for (char c : str) {
        if (c >= '0' && c <= '9') {
            result = result * 10 + (c - '0');
        }
        else {
            return 0;
        }
    }

    return result * sign;
}

// Конструктор по умолчанию
Term::Term(): coef(0), degree(0) {}

// Конструктор, принимающий коэффициент и степень
Term::Term(int coef, int degree): coef(coef), degree(degree) {}

// Конструктор, принимающий строку вида "ax^b"
Term::Term(std::string str) {
    std::string curCoef = "";
    std::string curDegree = "";
    bool status = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'x') {  
            status = 1;  
            continue;
        }
        else if (str[i] == '^') {
            continue;
        }
        else {
            if (!status)
                curCoef += str[i];
            else
                curDegree += str[i];
        }
    } 
    if (curCoef == "") curCoef = "1";
    if (curDegree == "") {
        if (status) curDegree = "1";
        else curDegree = "0";
    } 
    coef = stringToInt(curCoef);
    degree = stringToInt(curDegree);   
}

// Оператор присваивания
Term& Term::operator= (const Term& t) {
    this->coef = t.coef;
    this->degree = t.degree;
    return *this;
}

// Оператор сравнения "меньше"
bool Term::operator< (const Term& t) {
    return this->degree < t.degree;
}

// Оператор сравнения "больше"
bool Term::operator> (const Term& t) {
    return this->degree > t.degree;
}

// Оператор сравнения "равно"
bool Term::operator== (const Term& t) {
    return this->degree == t.degree;
}

// Оператор сложения одночленов
Term operator+(Term a, Term b) {
  return Term(a.coef + b.coef, a.degree);
}

// Оператор вывода одночлена в поток
std::ostream& operator<<(std::ostream& os, const Term& t) {
    if (!t.coef) return os;
    if (t.coef != 1)
        os << t.coef;
    if (!t.degree) return os;
    os << "x";
    if (!(t.degree - 1)) return os;
    os << "^" << t.degree;
    return os;
}

// Оператор ввода одночлена из потока
std::istream& operator>> (std::istream& in, Term& t) {
    std::string str;
    in >> str;
    Term newT(str);
    t = newT;
    return in;
}
