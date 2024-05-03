#include <bits/stdc++.h>
#include "myvector.h"

MyVector::MyVector(char *el, int maxsz) {
    maxsize = maxsz;
    size = 1;
    pdata = new char*[maxsize];
    pdata[0] = el;
}

MyVector::MyVector(char *el) {
    maxsize = MAX_SIZE;
    size = 1;
    pdata = new char*[maxsize];
    pdata[0] = el;
}

MyVector::MyVector() {
    maxsize = MAX_SIZE;
    size = 1;
    pdata = new char*[maxsize];
    pdata[0] = NULL;
}

MyVector::MyVector(MyVector &v) {
        maxsize = v.maxsize;
        size = v.size;
        pdata = new char*[maxsize];
        for (int i = 0; i < size; ++i) {
            pdata[i] = v.pdata[i];
        }
    }

MyVector::~MyVector() {
    delete[] pdata;
}

MyVector& MyVector::operator=(MyVector& v) {
    delete[] pdata;
    maxsize = v.maxsize;
    size = v.size;
    pdata = new char*[maxsize];
    for (int i = 0; i < size; ++i) {
        pdata[i] = v.pdata[i];
    }
    return *this;
}

char* MyVector::operator[](int i) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Index out of range");
    }
    return pdata[i];
}

int MyVector::Size() {
    return size;
}

int MyVector::Maxsize() {
    return maxsize;
}

void MyVector::add_element(char* item) {
    if (size == maxsize) {
        resize(maxsize * 2);
    }else if(size < maxsize / 4){
        resize(maxsize / 2);
    }
    pdata[size] = item;
    size++;
}

bool MyVector::delete_element(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; ++i) {
        pdata[i] = pdata[i + 1];
    }
    size--;
}

void MyVector::sort() {
    std::sort(pdata, pdata + size);
}

void MyVector::resize(int new_maxsize) {
    char** new_pdata = new char*[new_maxsize];
    for (int i = 0; i < size; ++i) {
        new_pdata[i] = pdata[i];
    }
    delete[] pdata;
    pdata = new_pdata;
    maxsize = new_maxsize;
}


std::ostream& operator<<(std::ostream& out, MyVector& v) {
    out << "MyVector: ";
    for (int i = 0; i < v.size; ++i) {
        out << v.pdata[i] << " ";
    }
    return out;
}