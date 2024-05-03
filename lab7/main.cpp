#include <bits/stdc++.h>
#include "classes/classes.cpp"

int main() {
    setlocale(LC_ALL, "Russian");
    Product product("Aboba", 100.12);
    Food food("Voda Baikalska", 12.23, 100000);
    Milkfood milkfood("milk", 50.33, 5);
    Toy toy("Palka", 1, "tree");
    Product::all_info();
    std::cout << "=============" << '\n';
    food.Show();
    toy.Show();
    std::cout << "=============" << '\n';
}