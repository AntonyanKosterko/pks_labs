#include <bits/stdc++.h>
#include "myset.h"

using namespace std;


template <typename T>
MySet<T>::MySet(T el) : MyVector<T>(el) {}

template <typename T>
MySet<T>::MySet() : MyVector<T>() {}

template <typename T>
MySet<T>& MySet<T>::operator=(const MySet<T>& s) {
    delete[] this->pdata;
    this->maxsize = s.maxsize;
    this->size = s.size;
    this->pdata = new T[this->maxsize];
    for (int i = 0; i < this->size; ++i) {
        this->pdata[i] = s.pdata[i];
    }
    return *this;
}

template <typename T>
bool MySet<T>::operator==(MySet<T>& s) {
    if (this->size != s.size)
        return false;
    for (int i = 0; i < this->size; ++i) {
        if (strcmp(this->pdata[i], s.pdata[i]) != 0)
            return false;
    }
    return true;
}

template <typename T>
MySet<T>& MySet<T>::operator+=(MySet<T>& s) {
    T* newpdata = new T[size + s.size];
    merge(pdata, pdata + size, s.pdata, s.pdata + s.size, newpdata, [](T a,  T b) {
        return strcmp(a, b) < 0;
    });
    delete[] pdata;
    pdata = newpdata;
    size += s.size;
    T* last = unique(pdata, pdata + size, [](T a,  T b) {
        return strcmp(a, b) == 0;
    });
    size = distance(pdata, last);
    return *this;
}

template <typename T>
MySet<T>& MySet<T>::operator-=(MySet<T>& s) {
    T* newpdata = new T[size];
    T* last = set_difference(pdata, pdata + size, s.pdata, s.pdata + s.size, newpdata, [](T a,  T b) {
        return strcmp(a, b) < 0;
    });
    delete[] pdata;
    pdata = newpdata;
    size = distance(pdata, last);
    return *this;
}

template <typename T>
MySet<T>& MySet<T>::operator*=(MySet<T>& s) {
    T* newpdata = new T[min(size, s.size)];
    T* last = set_intersection(pdata, pdata + size, s.pdata, s.pdata + s.size, newpdata, [](T a,  T b) {
        return strcmp(a, b) < 0;
    });
    delete[] pdata;
    pdata = newpdata;
    size = distance(pdata, last);
    return *this;
}

template <typename T>
bool MySet<T>::is_element(T el) {
    for (int i = 0; i < size; ++i) {
        if (pdata[i] == el) {
            return true;
        }
    }
    return false;
}

template <typename T>
void MySet<T>::add_element(T el) {
    if (!is_element(el)) {
        add_element(el);
        sort();
    }
}

template <typename T>
void MySet<T>::delete_element(T el) {
    delete_element(el);
}

template <typename T>
bool MySet<T>::q_find(T item) {
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int mid = (l + r)/2;
        if (pdata[mid] == item) {
            return true;
        }else if (pdata[mid] < item) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    return false;
}

template <typename T>
MySet<T> operator+(MySet<T> s1, MySet<T> s2) {
    int newSize = s1.size + s2.size;
    T* newpdata = new T[newSize];
    merge(s1.pdata, s1.pdata + s1.size, s2.pdata, s2.pdata + s2.size, newpdata, [](T a,  T b) {
        return strcmp(a, b) < 0;
    });
    MySet<T> newset = MySet<T>();
    newset.pdata = newpdata;
    newset.size = newSize;
    newset.maxsize = newSize + 1;
    return newset;
}

template <typename T>
MySet<T> operator-(MySet<T> s1, MySet<T> s2) {
    T* newpdata = new T[s1.size];
    T* last = set_difference(s1.pdata, s1.pdata + s1.size, s2.pdata, s2.pdata + s2.size, newpdata, [](T a,  T b) {
        return strcmp(a, b) < 0;
    });
    int newSize = distance(newpdata, last);
    MySet<T> newset = MySet<T>();
    newset.pdata = newpdata;
    newset.size = newSize;
    newset.maxsize = newSize+1;
    return newset;
}

template <typename T>
MySet<T> operator*(MySet<T> s1, MySet<T> s2) {
    T* newpdata = new T[min(s1.size, s2.size)];
    T* last = set_intersection(s1.pdata, s1.pdata + s1.size, s2.pdata, s2.pdata + s2.size, newpdata, [](T a,  T b) {
        return strcmp(a, b) < 0;
    });
    int newSize = distance(newpdata, last);
    MySet<T> newset = MySet<T>();
    newset.pdata = newpdata;
    newset.size = newSize;
    newset.maxsize = newSize+1;
    return newset;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, MySet<T>& s) {
    out << "MySet: ";
    for (int i = 0; i < s.size; ++i) {
        out << s.pdata[i] << " ";
    }
    return out;
}

// Специализация для char*

template <>
MySet<char*>::MySet(char* el) : MyVector<char*>(el) {}

template <>
MySet<char*>::MySet() : MyVector<char*>() {}

template <>
MySet<char*>& MySet<char*>::operator=(const MySet<char*>& s) {
    if (this != &s) {
        MyVector<char*>::operator=(s);
    }
    return *this;
}

template <>
void MySet<char*>::add_element(char* el) {
    if (!is_element(el)) {
        MyVector<char*>::add_element(el);
        sort();
    }
}

template <>
bool MySet<char*>::q_find(char* item) {
    int l = 0;
    int r = this->size - 1;
    while (l <= r) {
        int mid = (l + r)/2;
        if (strcmp(this->pdata[mid], item) == 0) {
            return true;
        } else if (strcmp(this->pdata[mid], item) < 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
}
