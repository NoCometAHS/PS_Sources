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

    if (!a || !b) {
        cout << c*c - (a + b);
    }
    else {
        cout << int(sqrt(a+b));
    }
    return 0;
}
