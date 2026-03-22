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

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l+1; r < n; r++) {
            int sum = 0;
            for (int i = l; i <= r; i++) sum += arr[i];

            bool flag = true;
            for (int i = l; i <= r; i++) {
                if (sum % arr[i]) continue;

                flag = false;
                break;
            }

            ans += flag;
        }
    }

    cout << ans;
    
    return 0;
}
