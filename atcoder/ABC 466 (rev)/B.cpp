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

    vector<int> arr(m, -1);
    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;

        arr[c-1] = max(arr[c-1], s);
    }

    for (auto& i : arr) cout << i << ' ';

    return 0;
}