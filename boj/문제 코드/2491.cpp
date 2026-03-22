#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int f(vector<int>& arr) {
    int ret = 1, cur = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i-1] > arr[i]) {
            cur = 1;
        }
        else {
            ret = max(ret, ++cur);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    int ans = f(arr);

    reverse(arr.begin(), arr.end());

    cout << max(ans, f(arr));

    return 0;
}
