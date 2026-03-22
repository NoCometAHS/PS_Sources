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

    vector<int> arr(14);
    for (auto& i : arr) cin >> i;

    int bnp[2] = {n, 0};
    for (int i : arr) {
        if (bnp[0] < i) continue;
        bnp[1] += bnp[0]/i;
        bnp[0] %= i;
    }

    int timing[2] = {n, 0};
    for (int i = 0; i < 11; i++) {
        int cost = arr[i+3];

        if (arr[i] < arr[i+1] && arr[i+1] < arr[i+2]) {
            timing[0] += timing[1] * cost;
            timing[1] = 0;
        }
        else if (arr[i] > arr[i+1] && arr[i+1] > arr[i+2]) {
            if (timing[0] < cost) continue;
            timing[1] += timing[0] / cost;
            timing[0] %= cost;
        }
    }

    int res1 = bnp[0] + bnp[1] * arr.back(), res2 = timing[0] + timing[1] * arr.back();
    if (res1 > res2) {
        cout << "BNP";
    }
    else if (res1 < res2) {
        cout << "TIMING";
    }
    else {
        cout << "SAMESAME";
    }

    return 0;
}
