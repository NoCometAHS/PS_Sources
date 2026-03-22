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
    unordered_multiset<string> chk;
    while (n--) {
        string str;
        char ch;

        cin >> str >> ch;

        if (ch == '+') {
            chk.insert(str);
        }
        else {
            if (chk.count(str) == 0) ans++;
            else chk.erase(chk.find(str));
        }
    }

    cout << ans + chk.size();
    return 0;
}
