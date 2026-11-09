#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int a, b;
    cin >> a >> b;

    int t = a+b, ans = 0;
    while (t) {
        t/=10;
        ans++;
    }

    cout << ans;
    return 0;
}