#include <bits/stdc++.h>

using namespace std;

void print(vector<double>& f){
    cout << "Элементы вектора: ";
    for(int i = 0; i < f.size(); ++i){
        cout << f[i] << " ";
    }
    cout << '\n';
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    vector<double> f(10);
    uniform_real_distribution<double> dis(-50, 50);
    double s = 0;
    for(int i = 0; i < f.size(); ++i){
        f[i] = dis(gen);
        s += f[i];
    }
    double sr = s / 10;
    print(f);
    cout << "Среднее значение: " << sr << '\n';
    vector<double> f2;
    for(int i = 0; i < f.size(); ++i){
        if(f[i] > sr)f2.push_back(f[i]);
    }
    print(f2);
    f.erase(f.begin() + 7);
    print(f);
    return 0;
}
