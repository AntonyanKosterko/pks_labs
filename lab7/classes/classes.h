#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>

class Product {
protected:
    std::string name;
    double price;  
    static std::vector<Product*> products;

    void Add();
public:
    Product(std::string name, double price);
    virtual ~Product();
    static void all_info();
    virtual void Show();
};

class Food : public Product {
protected:
    int expiration_date;
public:
    Food(std::string name, double price, int expiration_date);
    virtual void Show();
    virtual ~Food();
};

class Milkfood : public Food {
public:
    Milkfood(std::string name, double price, int expiration_date); 
    virtual void Show();
    virtual ~Milkfood();
};

class Toy : public Product {
protected:
    std::string material;
public:
    Toy(std::string name, double price, std::string material); 
    virtual void Show();
    virtual ~Toy();    
};
#endif