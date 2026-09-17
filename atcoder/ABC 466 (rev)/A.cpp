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

    bool ans = true;
    vector<int> arr(n);
    for (auto& i : arr) {
        cin >> i;

        ans &= i < 0;
    }

    if (ans) cout << "Yes";
    else cout <<  "No";

    return 0;
}

