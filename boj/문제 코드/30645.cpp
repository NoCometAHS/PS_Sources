#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c, n;
    cin >> r >> c >> n;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int>());

    vector<int> front(c, 0);

    int idx = 0, ans = 0;
    for (int i = 0; !arr.empty() &&i < r; i++) {
        for (int k = 0; !arr.empty() && k < c; k++) {
            while (!arr.empty() && front[k] >= arr.back()) arr.pop_back();

            if (!arr.empty()) {
                ans++;
                front[k] = arr.back();
                arr.pop_back();
            }
        }
    }

    cout << ans;
    
    return 0;
}
