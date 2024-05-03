#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string get_upper(string text){
    string ans;
    for(int i = 0; i < text.size(); ++i){
        if(isupper(text[i])) ans += text[i];
    }
    return ans;
}

string get_lower(string text){
    string ans;
    for(int i = 0; i < text.size(); ++i){
        if(islower(text[i])) ans += text[i];
    }
    return ans;
}

int get_digit(string text){
    int cnt = 0;
    for(int i = 0; i < text.size(); ++i){
        if(isdigit(text[i])) cnt++;
    }
    return cnt;
}

int main() {
    freopen("text.txt", "r", stdin);
    ofstream file1("ans1.txt");
    ofstream file2("ans2.txt");
    if (!file1.is_open() || !file2.is_open()) {
        cerr << "Ошибка открытия файлов" << endl;
        return 1;
    }
    int ans3 = 0;
    string line;
    while(getline(cin, line)){
        cout << line << '\n';
        string a = get_upper(line);
        string b = get_lower(line);
        ans3 += get_digit(line);
        file1 << a;
        file2 << b;
    }
    cout << ans3;
    file1.close();
    file2.close();
    return 0;
}