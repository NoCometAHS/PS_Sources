#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int func(int n) {
    if (n == 0) return 2;
    if (n >= 5) return 10 - n;
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    cout << func(n % 8);

    return 0;
}
