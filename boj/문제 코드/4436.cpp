#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    while (cin >> n) {
        unordered_set<int> chk;

        LL ans = 0;
        while (chk.size() < 10) {
            ans++;
            for (LL t = n * ans; t; t /= 10) chk.insert(t % 10);
        }

        cout << ans << '\n';
    }
    return 0;
}
