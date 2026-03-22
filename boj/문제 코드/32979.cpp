#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, qcnt;
    cin >> n >> qcnt;

    vector<int> arr(n*2);
    for (auto& i : arr) cin >> i;

    int cur = 0;
    while (qcnt--) {
        int q;
        cin >> q;

        cur = (cur + q - 1) % (n*2);

        cout << arr[cur] << '\n';
    }

    return 0;
}
