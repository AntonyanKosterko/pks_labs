#include <bits/stdc++.h>
#include "myvector.h"


template <typename T>
MyVector<T>::MyVector(T el, int maxsz) {
    this->maxsize = maxsz;
    this->size = 1;
    this->pdata = new T[this->maxsize];
    this->pdata[0] = el;
}

template <typename T>
MyVector<T>::MyVector(T el) {
    this->maxsize = MAX_SIZE;
    this->size = 1;
    this->pdata = new T[this->maxsize];
    this->pdata[0] = el;
}

template <typename T>
MyVector<T>::MyVector() {
    this->maxsize = MAX_SIZE;
    this->size = 1;
    this->pdata = new T[this->maxsize];
    this->pdata[0] = NULL;
}

template <typename T>
MyVector<T>::MyVector(const MyVector &v) {
        maxsize = v.maxsize;
        size = v.size;
        pdata = new T[maxsize];
        for (int i = 0; i < size; ++i) {
            pdata[i] = v.pdata[i];
        }
    }

template <typename T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& v) {
    delete[] pdata;
    maxsize = v.maxsize;
    size = v.size;
    pdata = new T[maxsize];
    for (int i = 0; i < size; ++i) {
        pdata[i] = v.pdata[i];
    }
    return *this;
}

template <typename T>
T& MyVector<T>::operator[](int i) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Index out of range");
    }
    return pdata[i];
}

template <typename T>
int MyVector<T>::Size() {
    return size;
}

template <typename T>
int MyVector<T>::Maxsize() {
    return maxsize;
}

template <typename T>
void MyVector<T>::add_element(T item) {
    if (size == maxsize) {
        resize(maxsize * 2);
    }else if(size < maxsize / 4){
        resize(maxsize / 2);
    }
    pdata[size] = item;
    size++;
}

template <typename T>
bool MyVector<T>::delete_element(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; ++i) {
        pdata[i] = pdata[i + 1];
    }
    size--;
}

template <typename T>
void MyVector<T>::sort() {
    std::sort(pdata, pdata + size);
}

template <typename T>
void MyVector<T>::resize(int new_maxsize) {
    T* new_pdata = new T[new_maxsize];
    for (int i = 0; i < size; ++i) {
        new_pdata[i] = pdata[i];
    }
    delete[] pdata;
    pdata = new_pdata;
    maxsize = new_maxsize;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, MyVector<T>& v) {
    out << "MyVector: ";
    for (int i = 0; i < v.size; ++i) {
        out << v.pdata[i] << " ";
    }
    return out;
}