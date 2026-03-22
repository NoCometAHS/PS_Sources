#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int func (int a, char op, int b) {
switch(op) {
    case '+': return a + b;
    case '-': return a - b;
    case '/': return a / b;
    case '*': return a * b;
}

return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n1, n2, n3;
    char op1, op2;

    cin >> n1 >> op1 >> n2 >> op2 >> n3;

    int res1 = func(func(n1, op1, n2), op2, n3), res2 = func(n1, op1, func(n2, op2, n3));

    cout << min(res1, res2) << '\n' << max(res1, res2);

    return 0;
}
