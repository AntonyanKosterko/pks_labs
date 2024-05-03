#include <bits/stdc++.h>

using namespace std;

int get_ans(map<string, int>& d, int y){
    switch(y){
        case 1: 
            return d["1а"] + d["1б"];
            break;
        case 2:
            return d["2"];
            break;
        case 3:
            return d["3а"] + d["3б"];
            break;
        case 4:
            return d["4а"] + d["4б"];
            break;
        case 5:
            return d["5а"] + d["5б"];
            break;
        case 6:
            return d["6а"] + d["6б"];
            break;
        case 7:
            return d["7а"] + d["7б"];
            break;
        case 8:
            return d["8"];
            break;
        case 9:
            return d["9"];
            break;
        case 10:
            return d["10"];
            break;
        case 11:
            return d["11"];
            break;
        default:
            cout << "Неправильный ввод" << std::endl;
            break;
    }
}

void print(map<string, int>& d) {
    cout << "Содержимое отображения:\n";
    for (auto pair : d) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    map<string, int> d = {
        {"1а", 21},
        {"1б", 20},
        {"2", 25},
        {"3а", 20},
        {"3б", 23},
        {"4а", 25},
        {"4б", 25},
        {"5а", 26},
        {"5б", 25},
        {"6а", 19},
        {"6б", 18},
        {"7а", 26},
        {"7б", 25},
        {"8", 25},
        {"9", 17},
        {"10", 15},
        {"11", 14}
    };

    int year;
    cin >> year;
    cout << "Год обучения: " << year << '\n';
    int ans = get_ans(d, year);
    cout << "Количество: " << ans << '\n';
    print(d);
    return 0;
}
