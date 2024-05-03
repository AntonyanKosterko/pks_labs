#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>

const int MAX_SIZE = 5;

class MyVector {
public:
    MyVector(char *el, int maxsz);
    MyVector(char *el);
    MyVector();
    MyVector(MyVector &v);

    ~MyVector();

    void add_element(char* item);
    bool delete_element(int index);
    char *operator[](int i);
    void sort();

    int Size();
    int Maxsize();
    int find(char *el);

    MyVector &operator=(MyVector &v);
    friend std::ostream &operator<<(std::ostream &out, MyVector &v);
protected:
    int maxsize;
    int size;
    char **pdata;
private:
    void resize(int new_maxsize);
};

#endif //INHERITANCE_MYVECTOR_H
