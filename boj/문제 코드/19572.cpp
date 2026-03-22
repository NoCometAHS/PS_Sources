#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    double a, b, c;
    b = (d1 - d2 + d3)/2;
    a = d1 - b;
    c = d3 - b;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
    }
    else {
        cout << 1 << '\n';
        cout << fixed;
        cout.precision(1);
        cout << a << ' ' << b << ' ' << c;
    }

    

    return 0;
}

/*
d1 = a + b 
d2 = a + c
d3 = b + c


d1 - d2 + d3 = a + b -a -c + b +c
= 2b
*/