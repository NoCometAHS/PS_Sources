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

    map<string, int> chk;
    bool ans = false;
    while (n--) {
        string s;
        int c;
        cin >> s >> c;

        chk[s] += c;
    }

    for (auto& [s, c] : chk) {
        if (c == 5) {
            ans = true;
            break;
        }

    }
    cout << (ans ? "YES" : "NO");

    return 0;
}
