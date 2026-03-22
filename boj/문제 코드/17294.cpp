#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    bool f = true;
    for (int i = 1; i < str.length() - 1; i++) {
        if (str[i-1] - str[i] == str[i] - str[i+1]) continue;

        f = false;
        break;
    }

    if (f) {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    }
    else {
        cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
    }

    return 0;
}
