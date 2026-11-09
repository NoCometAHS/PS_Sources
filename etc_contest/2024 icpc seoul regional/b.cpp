#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    TwoVector<int> arr(2, vector<int>(n));
    unordered_map<int,int> cnt;
    for (auto& v : arr) {
        for (auto& i : v) {
            cin >> i;
            cnt[i]++;
        }
    }

    unordered_set<int> chk;
    for (int i = 0; i < n; i++) {
        if (arr[0][i] == arr[1][i]) {
            chk.insert(arr[0][i]);
        }
    }

    for (auto& [k, v] : cnt) {
        if (v == 1) chk.insert(k);
    }

    unordered_set<int> left;
    for (int i = 0; i < n; i++) {
        if (cnt[arr[0][i]] == 1 || cnt[arr[1][i]] == 1) continue;

        if (chk.count(arr[0][i]) || chk.count(arr[1][i])) {
            chk.insert(arr[0][i]);
            chk.insert(arr[1][i]);
        }
        else {
            left.insert(arr[0][i]);
            left.insert(arr[1][i]);
        }
    }

    cout << chk.size() + left.size();



    return 0;
}