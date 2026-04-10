#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_set<string> chk{"i", "pa","te","ni","niti","a","ali","nego","no","ili"};

    string s, ans;
    while (cin >> s) {
        if (ans.length() != 0 && chk.count(s)) continue;

        ans.push_back(s.front() - 32);
    }
    cout << ans;

    return 0;
}