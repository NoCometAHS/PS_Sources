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
    int ans = 0;
    while (n--) {
        int a, b;
        int arr[5];
        cin >> a >> b;
        
        for (auto& i : arr) cin >> i;
        sort(arr, arr + 5);
        
        ans = max(ans, arr[4] + arr[3] + max(a,b));
    }

    cout << ans;

    return 0;
}
