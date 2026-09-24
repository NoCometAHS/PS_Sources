#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    vector<int> queries;
    while (q--) {
        int a;
        cin >> a;

        queries.push_back(a);
    }

    vector<bool> chk(n+1, false);
    vector<int> ans;

    for (int i = queries.size()-1; i >= 0; i--) {
        int a = queries[i];

        if (chk[a]) continue;
        chk[a] = true;

        ans.push_back(a);
    }

    for (int i = n-1; i >= 0; i--) {
        if (chk[arr[i]]) continue;

        ans.push_back(arr[i]);
    }


    reverse(ans.begin(), ans.end());

    for (auto& i : ans) cout << i << ' ';
    return 0;
}


// 마지막으로 불린게 가장 중요한 거 아니냐