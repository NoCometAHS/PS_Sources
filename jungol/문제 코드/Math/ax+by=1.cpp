#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

tuple<ll,ll,ll> extGcd(ll a, ll b) {
    if (b == 0) return {a, 1, 0};
    auto [g, x, y] = extGcd(b, a%b);
    return {g, y, x - a/b*y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    auto [g, x, y] = extGcd(a,b);

    if (g != 1) cout << "0 0";
    else {
        cout << x << ' ' << y;
    }
    
    return 0;
}