#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL k, n;
    cin >> k >> n;

    if (n == 1) cout << -1;
    else cout << (k * n + n - 2) / (n - 1);

    return 0;
}

/*
x <= (x-k)n

-nx + x <= -kn
(n-1)x >= kn
x >= kn/(n-1)
*/