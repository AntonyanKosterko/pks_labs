#include <bits/stdc++.h>

using namespace std;

#include <iostream>

class Box {
    double a;  // ширина
    double b;  // высота
    double c;  // длина
public:
    Box() : a(0), b(0), c(0) {}
    Box(double a, double b, double c) : a(a), b(b), c(c) {}
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    bool operator<(const Box& other) const {
        double volume = a * b * c;
        double other_volume = other.a * other.b * other.c;
        return volume < other_volume;
    }

    bool operator==(const Box& other) const {
        return a == other.a && b == other.b && c == other.c;
    }
};

void print_boxes(vector<Box>& boxes){
    cout << "Размеры коробок:\n";
    for(auto box : boxes){
        cout << box.getA() << " " << box.getB() << " " << box.getC() << '\n';
    }
}




int main() {
    random_device rd;
    mt19937 gen(rd());

    vector<Box> f;
    f.push_back(Box(1, 2, 63));
    f.push_back(Box(14, 57, 19));
    f.push_back(Box(7, 32, 20));
    f.push_back(Box(5, 13, 23));
    f.push_back(Box(10, 19, 45));
    f.push_back(Box(19, 9, 59));
    print_boxes(f);
    cout << '\n';
    Box maxx;
    for(int i = 0; i < f.size(); ++i){
        if(maxx < f[i]){
            maxx = f[i];
        }
    }
    cout << "Размеры самой большой коробки:\n";
    cout << maxx.getA() << " " << maxx.getB() << " " << maxx.getC() << '\n';
    return 0;
}
