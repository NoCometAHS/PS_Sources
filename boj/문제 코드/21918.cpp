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
    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            arr[b-1] = c;
        }
        else if (a == 2) {
            for (int i = b-1; i < c; i++) arr[i] = 1 - arr[i];
        }
        else if (a == 3) {
            for (int i = b-1; i < c; i++) arr[i] = 0;
        }
        else {
            for (int i = b-1; i < c; i++) arr[i] = 1;
        }
    }

    for (auto& i : arr) cout << i << ' ';
    return 0;
}
