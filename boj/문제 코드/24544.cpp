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

    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        ans1 += arr[i];
        if (!a) { 
            ans2 += arr[i];
        }
    }

    cout << ans1 << '\n' << ans2;
    return 0;
}
