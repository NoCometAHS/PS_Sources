#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL q, a, b;
    cin >> q;

    while (q--) {
        cin >> a >> b;

        if (b % a == 0 && b / a >= 2) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}

/*
x = a * c
y = a * d

(둘 다 1이 아닐 때, c != d)

a*c + a*d = b

a*(c+d) = b

a로 b가 나누어 떨어질때
몫이 2이상이다.


*/