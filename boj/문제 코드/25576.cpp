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

    vector<vector<int>> arr(n, vector<int>(m));

    for (auto& i :  arr) {
        for (auto& j : i) {
            cin >> j;
        }
    }

    int bad = 0;
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int k = 0; k < m; k++) {
            sum += abs(arr[0][k] - arr[i][k]);
        }

        bad += sum > 2000;
    }

    if (n-1 <= bad*2) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    

    return 0;
}
