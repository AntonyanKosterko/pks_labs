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
    std::random_device rd;
    std::mt19937 gen(rd());

    list<double> f(10);
    uniform_real_distribution<double> dis(-50, 50);
    double s = 0;
    for (auto& val : f) {
        val = dis(gen);
        s += val;
    }
    double sr = s / 10;
    print(f);
    cout << "Среднее значение: " << sr << '\n';
    
    list<double> f2;
    for (auto it = f.begin(); it != f.end(); ++it) {
        if (*it > sr) {
            f2.push_back(*it);
        }
    }
    print(f2);
    
    auto it = f.begin();
    advance(it, 7);
    f.erase(it);
    print(f);
    return 0;
}
