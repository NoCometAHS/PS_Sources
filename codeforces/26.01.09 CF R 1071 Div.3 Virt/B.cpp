#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (auto& i : arr)cin >> i;

        int sum = abs(arr[n-2] - arr[n-1]), mx = max(abs(arr[0] - arr[1]), abs(arr[n-2] - arr[n-1]));
        for (int i = 1; i < n-1; i++) {
            sum += abs(arr[i-1] - arr[i]);
            
            int pre = abs(arr[i-1] - arr[i]) + abs(arr[i] - arr[i+1]);
            int now = abs(arr[i-1] - arr[i+1]);

            mx = max(mx, pre - now);
        }

        cout << sum - mx << '\n';
    }
    return 0;
}