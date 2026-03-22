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

    string ansName;
    int mxLv = -1, ans  = 0;

    for (int i = 0; i < n; i++) {
        string name;
        int t, m, lv = 0;
        cin >> name >> t >> m;

        while (t <= m) {
            m -= t;
            m += 2;

            lv++;
            ans++;
        }

        if (mxLv < lv) {
            mxLv = lv;
            ansName = name;
        }
    }    

    cout << ans << '\n' << ansName;
    return 0;
}
