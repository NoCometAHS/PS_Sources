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
    cin.ignore();

    for (int t = 1; t <= n; t++) {
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);

        multiset<char> chk;
        for (auto& ch : str1) chk.insert(ch);

        int ans = 0;
        for (auto& ch : str2) {
            if (chk.count(ch)) chk.erase(chk.find(ch));
            else ans++;
        }

        cout << "Case #" << t << ": " << chk.size() + ans << '\n';
    }

    return 0;
}
