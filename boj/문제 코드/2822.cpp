#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<iipair> arr(8);

    for (int i = 0; i < 8; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end(), greater<iipair>());

    vector<int> ans;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += arr[i].first;
        ans.push_back(arr[i].second);
    }

    sort(ans.begin(), ans.end());

    cout << sum << '\n';
    for (auto& i : ans) cout << i+1 << ' ';
    return 0;
}
