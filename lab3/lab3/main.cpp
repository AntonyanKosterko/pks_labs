#include <iostream>
#include <cstring>
#include "fraction/fraction.h"

void demo(){
    char* s = "-4/18";
    Fraction z = s;

    // проверка конструкторов
    Fraction f0(10, 14), f1;
    std::cout << "f0 = " << f0 << std::endl;
    std::cout << "f1 = " << f1 << std::endl;
    char* s1 = "-1 4/8";
    Fraction f2 = s1;
    std::cout << "f2 = " << f2 << std::endl;
    Fraction x(z), y;
    std::cout << "x = " << x << std::endl;
    double flt = -1.25;
    Fraction f = flt;
    std::cout << "f = " << f << std::endl;

    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y = " << y << std::endl;
    y += x;
    f += flt / 2;
    std::cout << "f = " << f << std::endl;
    y = x + flt;
    std::cout << "y = " << y << std::endl;
    y = flt + y;
    std::cout << "y = " << y << std::endl;
    y += flt;
    std::cout << "y = " << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y = " << y << std::endl;
    y = i + x;
    std::cout << "y = " << y << std::endl;
    y = x + i;
    std::cout << "y = " << y << std::endl;
    y += flt + i + x;
    std::cout << "y = " << y << std::endl;
}

void interactive(){
    Fraction z;
    std::cin >> z;
    // проверка конструкторов
    Fraction f0(10, 14), f1;
    std::cout << "f0 = " << f0 << std::endl;
    std::cout << "f1 = " << f1 << std::endl;
    char* s = "-1 4/8";
    Fraction f2 = s;
    std::cout << "f2 = " << f2 << std::endl;
    Fraction x(z), y;
    std::cout << "x = " << x << std::endl;
    double dbl = -1.25;
    Fraction f = dbl;
    std::cout << "f = " << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y = " << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f = " << f << std::endl;
    y = x + dbl;
    std::cout << "y = " << y << std::endl;
    y = dbl + y;
    std::cout << "y = " << y << std::endl;
    y += dbl;
    std::cout << "y = " << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y = " << y << std::endl;
    y = i + x;
    std::cout << "y = " << y << std::endl;
    y = x + i;
    std::cout << "y = " << y << std::endl;
    y += dbl + i + x;
    std::cout << "y = " << y << std::endl;
    return;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int status = -1;
    char* message = "0 - Demo\n1 - Interactive\n";
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
