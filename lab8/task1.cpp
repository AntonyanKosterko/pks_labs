#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;
    getline(cin, text);
    vector<int> ans;
    ans.push_back(1);
    for(int i = 0; i < text.size(); ++i){
        if(text[i] == ' ')ans.push_back(i+1);
    }
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    return 0;
}
