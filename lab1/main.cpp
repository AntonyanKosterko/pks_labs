#include <iostream>
#include "mymath/mymath.cpp"
#include "mycat/mycat.cpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! hi 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;
    std::cout << mycat::cat() << std::endl;
    return 0;
}