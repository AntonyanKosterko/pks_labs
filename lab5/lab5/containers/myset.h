#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include "myvector.h"

template <typename T>
class MySet : public MyVector<T> {
public:
    MySet(T el);    
    MySet();

    MySet& operator=(const MySet& s);
    friend std::ostream &operator<<(std::ostream &out, MySet &s);
    friend MySet operator+(MySet s1, MySet s2);
    friend MySet operator-(MySet s1, MySet s2);
    friend MySet operator*(MySet s1, MySet s2);

    bool operator==(MySet &s);
    MySet &operator+=(MySet &s);
    MySet &operator-=(MySet &s);
    MySet &operator*=(MySet &s);

    void add_element(T el);
    void delete_element(T el);
    bool is_element(T el);
private:
    bool q_find(T item);
};

#endif //INHERITANCE_MYSET_H
