#include <bits/stdc++.h>

using namespace std;

void print(const list<double>& f) {
    cout << "Элементы списка: ";
    for (auto it = f.begin(); it != f.end(); ++it) {
        cout << *it << " ";
    }
    cout << '\n';
}

int main() {
    map<int, double> d;

    for (int i = 1; i <= 9; ++i) {
        d[i] = i * 100.0;
    }
    for (const auto& pair : d) {
        cout << pair.first << " - " << pair.second << endl;
    }
    double sum = 0.0;
    for (const auto& pair : d) {
        sum += pair.second;
    }

    cout << "\nОтображение после деления каждого значения на сумму:\n";
    for (auto pair : d) {
        pair.second /= sum;
        cout << pair.first << " - " << pair.second << endl;
    }

    return 0;
}
