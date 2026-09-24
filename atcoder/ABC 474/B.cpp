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

    
    bool ans = true;
    for (int i = 0; i < (n+9)/10; i++) {
        set<int> chk;
        for (int k = 0; k < 10 && k + i*10 < n; k++) {
            chk.insert(k + i*10+1);
        }

        for (int k = 0; k < 10 && k + i*10 < n; k++) {
            int t;
            cin >> t;
            
            if (chk.count(t)) chk.erase(t);
        }

        ans &= !chk.size();
    }
    
    cout << (ans ? "Yes" : "No");

    return 0;
}