#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

bool isSimilar(string a, string b) {
    unordered_map<char, char> mp;
    unordered_set<char> chk;
    for (int i = 0; i < a.length(); i++) {
        if (mp.count(a[i]) == 0) {
            if (chk.count(b[i])) return false;

            chk.insert(b[i]);
            mp[a[i]] = b[i];
        }
        else {
            if (mp[a[i]] != b[i]) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<string> arr(n);
    for (auto& i : arr) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            ans += isSimilar(arr[i], arr[k]);
        }
    }

    cout << ans;

    return 0;
}
