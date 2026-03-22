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

    for (int t = 1; t <= tc; t++) {
        string str;
        cin >> str;

        cout << "String #" << t << "\n";
        for (auto& ch : str) {
            ch++;
            cout << (ch > 'Z' ? 'A' : ch);
        }

        if (t != tc) cout << "\n";
        cout << "\n";
    }
    return 0;
}
