#include <bits/stdc++.h>

using namespace std;

int main() {
    string text, ans;
    getline(cin, text);
    for(int i = 0; i < text.size(); ++i){
        if(!isdigit(text[i]))ans += text[i];
    }
    cout << ans;
    return 0;
}
