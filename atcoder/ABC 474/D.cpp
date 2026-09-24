#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<LL> arr1(n), arr2(n);
    for (auto& i : arr1) cin >> i;
    for (auto& i : arr2) cin >> i;

    bool ans = false;
    vector<LL> w(n);
    for (int i = 0; i < n; i++) {
        if (arr1[i] <= arr2[i]) {
            w[i] = 1;
            continue;
        }

        ans = true;
        w[i] = 1e18;
    }

    if (ans) {
        cout << "Yes\n";
        for (auto& i : w) {
            cout << i << ' ';
        }
    }
    else {
        cout << "No";
    }

    return 0;
}