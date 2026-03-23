#include "bits/stdc++.h"

using namespace std;
using LL = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> ans;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        auto cur = ans.end();

        int m;
        cin >> m;

        cur -= m;

        ans.insert(cur, i+1);
    }

    for (auto& i : ans) cout << i << ' ';
    return 0;
}