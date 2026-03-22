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
    string str;
    cin >> str;

    for (int lt = 0, rt = str.length() - 1; lt <= rt; lt++, rt--) {
        int cnt = (str[lt] == '?') + (str[rt] == '?');
        if (cnt == 0) continue;
        if (cnt == 1) {
            str[lt] = str[rt] = (str[lt] == '?' ? str[rt] : str[lt]);
        }
        else {
            str[lt] = str[rt] = 'a';
        }
    }

    cout << str;
    return 0;
}
