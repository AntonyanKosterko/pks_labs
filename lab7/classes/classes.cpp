#include "classes.h"

std::vector<Product*> Product::products;

void Product::Add(){
    products.push_back(this);
}

void Product::all_info(){
    for(auto p : products)
        p->Show();
}

Product::Product(std::string name, double price): name(name), price(price){
    Add();
}

Product::~Product(){
    name.clear();
}

void Product::Show(){
    std::cout << name << ' ' << price << '\n';
}

Food::Food(std::string name, double price, int expiration_date): Product(name, price), expiration_date(expiration_date){}

void Food::Show(){
    std::cout << name << ' ' << price << ' ' << expiration_date << '\n';
}

Food::~Food(){
    name.clear();
}

Milkfood::Milkfood(std::string name, double price, int expiration_date): Food(name, price, expiration_date) {}

void Milkfood::Show(){
    std::cout << name << ' ' << price << ' ' << expiration_date << '\n';
}

Milkfood::~Milkfood(){
    name.clear();
}

Toy::Toy(std::string name, double price, std::string material): Product(name, price), material(material){}

void Toy::Show(){
    std::cout << name << ' ' << price << ' ' << material << '\n';
}

Toy::~Toy(){
    name.clear();
    material.clear();
}