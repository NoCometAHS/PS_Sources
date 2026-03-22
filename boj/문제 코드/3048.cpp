#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string str1, str2;

    cin >> n >> m >> str1 >> str2;
    reverse(str1.begin(), str1.end());

    vector<int> order(n+m);
    iota(order.begin(), order.end(), 1);

    int t;
    cin >> t;

    for (int i = n; i < n+m; i++) {
        order[i] -= t;
    }

    string ans;
    int i = 0, j = n;
    while (i < n && j < n+m) {
        if (order[i] < order[j]) {
            ans.push_back(str1[i]);
            i++;
        }
        else {
            ans.push_back(str2[j - n]);
            j++;
        }
    }

    while (i < n) {
        ans.push_back(str1[i++]);
    }

    
    while (j < n + m) {
        ans.push_back(str2[j++ - n]);
    }

    cout << ans;
    return 0;
}
