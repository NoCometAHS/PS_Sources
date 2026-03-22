#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    vector<int> temp(n);
    while (m--) {
        int b, e, m;
        cin >> b >> e >> m;
        b--, e--, m--;


        temp = arr;
        for (int i = m; i <= e; i++) {
            temp[b + i - m] = arr[i];
        }

        for (int i = b; i < m; i++) {
            temp[(e - m) + 1 + i] = arr[i];
        }

        swap(arr, temp);

    }

        for (auto& i : arr) cout << i << ' ';

    return 0; 
}
