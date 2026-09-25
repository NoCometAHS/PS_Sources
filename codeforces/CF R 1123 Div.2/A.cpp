#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        char ch;
        cin >> n >> ch;

        string str;
        cin >> str;

        int ans = 0;
        for (int lt = 0, rt = str.length()-1; lt < rt; lt++, rt--) {
            if (str[lt] == str[rt]) continue;

            if (str[lt] == ch || str[rt] == ch) ans++;
            else ans += 2;
        }

        cout << ans << '\n';
    }
    

    return 0;
}

