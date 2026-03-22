#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, p;
    cin >> n;
    while (n) {
        cin >> p;
        int a = p;

        if (p > n/2) {
            p = n - p + 1;
        }

        if (p % 2 == 0) p--;

        vector<int> ans{p, p+1, n - p, n - p + 1};
        for (auto& i : ans) {
            if (i == a) continue;
            cout << i << ' ';
        }
        cout << '\n';

        cin >> n;
    } 
    return 0;
}
