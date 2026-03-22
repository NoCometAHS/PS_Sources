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

    vector<int> arr;
    vector<int> cnt(2000001, 0);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        arr.push_back(num);
        cnt[num]++;
    }

    int x;
    cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cnt[arr[i]]--;

        if (x <= arr[i]) continue;
        ans += cnt[x - arr[i]];
    }

    cout << ans;

    return 0;
}
