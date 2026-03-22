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

    sort(arr.begin(), arr.end(), greater<>());
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max<LL>(0, arr[i] - i);
    }

    cout << ans;
    return 0;
}

/*
큰 음수를 작은 수에 더해버리면 손해가 가장 적어지겠는데?
내림차순으로 주기?

*/