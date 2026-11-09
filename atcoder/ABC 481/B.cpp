#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (auto& i : arr) cin >> i;

    int ans = arr[0] == K;
    for (int i = 0; i < N-1; i++) {
        int l = arr[i], h = arr[i+1];
        if (l > h){
            swap(l, h);
            if (l <= K and K < h) ans++;
        }
        else {
            if (l < K and K <= h) ans++;
        }
        
    }

    cout << ans;

    return 0;
}