#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    map<int, int> cnt;
    while (m--) {
        int a, b;
        cin >> a >> b;

        cnt[a]++;
        cnt[b]++;
    }

    for (int i = 1; i <= n; i++) {
        cnt[i] = n - cnt[i] - 1;
        cout << cnt[i] * (cnt[i]-1) * (cnt[i]-2) / 3 / 2<< ' ';
    }
    return 0;
}