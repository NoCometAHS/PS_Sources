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

    vector<int> arr(n*n);
    for (auto& i : arr) cin >> i;

    sort(arr.rbegin(), arr.rend());
    cout << arr[n-1];
    return 0;
}
