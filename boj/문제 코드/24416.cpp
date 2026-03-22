#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

LL ans1, ans2;

LL fib(LL n) {
    if (n == 1 || n == 2) {
        ans1++;
        return 1;
    }
    return fib(n-1) + fib(n-2);
}


LL fibonacci(LL n) {
    vector<LL> f(44, 0);
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        ans2++;
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    fib(n), fibonacci(n);
    cout << ans1 << ' ' << ans2;
    return 0;
}
