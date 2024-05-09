#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>

const int MAX_SIZE = 5;

template <typename T>
class MyVector {
public:
    MyVector(T el, int maxsz);
    MyVector(T el);
    MyVector();
    MyVector(const MyVector &v);

    ~MyVector();

    void add_element(T item);
    bool delete_element(int index);
    T& operator[](int i);
    void sort();

    int Size();
    int Maxsize();
    int find(T el);

    MyVector &operator=(const MyVector &v);
    friend std::ostream &operator<<(std::ostream &out, MyVector &v);
protected:
    int maxsize;
    int size;
    T *pdata;
private:
    void resize(int new_maxsize);
};

#endif //INHERITANCE_MYVECTOR_H
