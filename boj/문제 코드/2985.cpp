#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c) cout << a << "+" << b <<"=" << c;
    else if (a - b == c) cout << a << "-" << b <<"=" << c;
    else if (a * b == c) cout << a << "*" << b <<"=" << c;
    else if (a / b == c) cout << a << "/" << b <<"=" << c;
    else if (b + c == a) cout << a << "=" << b <<"+" << c;
    else if (b - c == a) cout << a << "=" << b <<"-" << c;
    else if (b * c == a) cout << a << "=" << b <<"*" << c;
    else if (b / c == a) cout << a << "=" << b <<"/" << c;
    
    return 0;
}
