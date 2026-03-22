#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<iipair> arr(n);
    for (auto& [st,en] : arr) {
        int x, y;
        cin >> x >> y;

        st = x;
        en = x + y;
    }
    arr.emplace_back(s,s);

    sort(arr.begin(), arr.end());

    int prvEn = 0;
    for (auto& [st, en] : arr) {
        if (prvEn + m <= st) {
            cout << prvEn;
            return 0;
        }    

        prvEn = en;
    }

    cout << -1;
    return 0;
}
