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

    int ans = 0;
    while(n--) {
        string str;
        cin >> str;

        bool f = true;
        for (int lt = 0, rt = str.length()-1; lt < rt; lt++, rt--) {
            if (str[lt] != str[rt]) {
                f = false;
                break;
            }
        }

        ans += f;
    }

    cout << ans * (ans-1);
    return 0;
}
