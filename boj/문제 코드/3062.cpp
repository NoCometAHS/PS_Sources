#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        string n;
        cin >> n;

        string rn = n;
        reverse(rn.begin(), rn.end());

        int res = stoi(n) + stoi(rn);

        string sres = to_string(res);

        bool ans = true;
        for (int l = 0, r = sres.length() - 1; l < r; l++, r--) {
            ans &= sres[l] == sres[r];
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}