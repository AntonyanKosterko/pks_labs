#include <bits/stdc++.h>

using namespace std;

#include <iostream>

class Graduate {
    string name;    // фамилия
    double rating;  // рейтинг
public:
    Graduate() {
        name = "";
        rating = 0;
    }
    Graduate(string Name, double Rating) {
        name = Name;
        rating = Rating;
    }

    string getName() const { return name; }
    double getRating() const { return rating; }

    bool operator<(const Graduate& other) const {
        return rating < other.rating;
    }

    bool operator==(const Graduate& other) const {
        return name == other.name && rating == other.rating;
    }

    Graduate& operator+=(double a) {
        rating += a;
        return *this;
    }
};

void print_students(list<Graduate>& students){
    cout << "Студенты:\n";
    for(auto student : students){
        cout << student.getName() << " " << student.getRating() << '\n';
    }
}




int main() {
    random_device rd;
    mt19937 gen(rd());

    list<Graduate> f;
    f.push_back(Graduate("Иванов", 99));
    f.push_back(Graduate("Петров", 430));
    f.push_back(Graduate("Семенов", 70));
    f.push_back(Graduate("Котов", 540));
    f.push_back(Graduate("Белых",230));
    f.push_back(Graduate("Черных", 350));
    print_students(f);
    cout << '\n';

    Graduate maxx;
    for (auto it = f.begin(); it != f.end(); ++it) {
        if (maxx < *it) {
            maxx = *it;
        }
    }
    
    cout << "Лучший студент:\n";
    cout << maxx.getName() << " " << maxx.getRating() << '\n';
    
    int p;
    cin >> p;
    for (auto it = f.begin(); it != f.end(); ++it) {
        *it += p;
    }
    print_students(f);
    return 0;
}
