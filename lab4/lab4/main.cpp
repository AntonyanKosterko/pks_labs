#include <bits/stdc++.h>
#include "MyStack/MyStack.cpp"

using namespace std;

template<class DATA>
void Multipliers(int n, MyStack<DATA> &stack){
    for(int i = 2; i*i < n; ++i){
        while(n % i == 0){
            stack.push(i);
            n /= i;
        }
    }
    if(n != 1)stack.push(n);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N = 500000;
    MyStack<int> stack;
    Multipliers(N, stack);
    vector<int> ans;
    while (!stack.empty()) {
        ans.push_back(stack.top_inf());
        stack.pop();
    }
    cout << N << "=";
    for(int i = 0; i < ans.size(); ++i){
        if(i == ans.size()-1){
            cout << ans[i];
            break;
        }
        cout << ans[i] << " * ";
    }
    cout << '\n';
    cout << N << "=";
    for(int i = ans.size()-1; i >= 0; --i){
        if(i == 0){
            cout << ans[i];
            break;
        }
        cout << ans[i] << " * ";
    }
    return 0;
}