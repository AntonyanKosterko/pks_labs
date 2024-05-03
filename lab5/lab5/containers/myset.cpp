#include <bits/stdc++.h>
#include "myset.h"

using namespace std;


MySet::MySet(char *el) : MyVector(el) {};
MySet::MySet() : MyVector() {};
MySet& MySet::operator=(const MySet& s) {
    delete[] pdata;
    maxsize = s.maxsize;
    size = s.size;
    pdata = new char*[maxsize];
    for (int i = 0; i < size; ++i) {
        pdata[i] = s.pdata[i];
    }
    return *this;
}

bool MySet::operator==(MySet& s) {
    if (size != s.size)
        return false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(pdata[i], s.pdata[i]) != 0)
            return false;
    }
    return true;
}

MySet& MySet::operator+=(MySet& s) {
    char** newpdata = new char*[size + s.size];
    merge(pdata, pdata + size, s.pdata, s.pdata + s.size, newpdata, [](char* a,  char* b) {
        return strcmp(a, b) < 0;
    });
    delete[] pdata;
    pdata = newpdata;
    size += s.size;
    char** last = unique(pdata, pdata + size, [](char* a,  char* b) {
        return strcmp(a, b) == 0;
    });
    size = distance(pdata, last);
    return *this;
}

MySet& MySet::operator-=(MySet& s) {
    char** newpdata = new char*[size];
    char** last = set_difference(pdata, pdata + size, s.pdata, s.pdata + s.size, newpdata, [](char* a,  char* b) {
        return strcmp(a, b) < 0;
    });
    delete[] pdata;
    pdata = newpdata;
    size = distance(pdata, last);
    return *this;
}

MySet& MySet::operator*=(MySet& s) {
    char** newpdata = new char*[min(size, s.size)];
    char** last = set_intersection(pdata, pdata + size, s.pdata, s.pdata + s.size, newpdata, [](char* a,  char* b) {
        return strcmp(a, b) < 0;
    });
    delete[] pdata;
    pdata = newpdata;
    size = distance(pdata, last);
    return *this;
}

bool MySet::is_element(char *el) {
    for (int i = 0; i < size; ++i) {
        if (pdata[i] == el) {
            return true;
        }
    }
    return false;
}

void MySet::add_element(char *el) {
    if (!is_element(el)) {
        add_element(el);
        sort();
    }
}

void MySet::delete_element(char *el) {
    delete_element(el);
}

bool MySet::q_find(char* item) {
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


MySet operator+(MySet s1, MySet s2) {
    int newSize = s1.size + s2.size;
    char** newpdata = new char*[newSize];
    merge(s1.pdata, s1.pdata + s1.size, s2.pdata, s2.pdata + s2.size, newpdata, [](char* a,  char* b) {
        return strcmp(a, b) < 0;
    });
    MySet newset = MySet();
    newset.pdata = newpdata;
    newset.size = newSize;
    newset.maxsize = newSize + 1;
    return newset;
}

MySet operator-(MySet s1, MySet s2) {
    char** newpdata = new char*[s1.size];
    char** last = set_difference(s1.pdata, s1.pdata + s1.size, s2.pdata, s2.pdata + s2.size, newpdata, [](char* a,  char* b) {
        return strcmp(a, b) < 0;
    });
    int newSize = distance(newpdata, last);
    MySet newset = MySet();
    newset.pdata = newpdata;
    newset.size = newSize;
    newset.maxsize = newSize+1;
    return newset;
}

MySet operator*(MySet s1, MySet s2) {
    char** newpdata = new char*[min(s1.size, s2.size)];
    char** last = set_intersection(s1.pdata, s1.pdata + s1.size, s2.pdata, s2.pdata + s2.size, newpdata, [](char* a,  char* b) {
        return strcmp(a, b) < 0;
    });
    int newSize = distance(newpdata, last);
    MySet newset = MySet();
    newset.pdata = newpdata;
    newset.size = newSize;
    newset.maxsize = newSize+1;
    return newset;
}

std::ostream& operator<<(std::ostream& out, MySet& s) {
    out << "MySet: ";
    for (int i = 0; i < s.size; ++i) {
        out << s.pdata[i] << " ";
    }
    return out;
}