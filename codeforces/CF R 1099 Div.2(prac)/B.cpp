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
        LL n;
        cin >> n;

        vector<LL> arr(n);
        for (auto& i : arr) cin >> i;

        LL k = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] <= arr[i]) continue;

            k = max(k, arr[i - 1] - arr[i]);
        }

        for (int i = 1; i < n; i++) {
            if (arr[i - 1] <= arr[i]) continue;

            arr[i] += k;
        }

        bool ans = true;
        for (int i = 1; i < n; i++) {
            ans &= arr[i-1] <= arr[i];
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
/*
그냥 연속한 내림차순만 없으면 되는 것 같은데

*/