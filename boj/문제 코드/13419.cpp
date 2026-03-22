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
        string str;
        cin >> str;
        str.append(str);

        string a1, a2;
        set<char> chk1, chk2;
        for (int i = 0; i < str.length(); i+=2) {
            if (chk1.count(str[i])) break;
            chk1.insert(str[i]);
            a1.push_back(str[i]);
        }

        for (int i = 1; i < str.length(); i+=2) {
            if (chk2.count(str[i])) break;
            chk2.insert(str[i]);
            a2.push_back(str[i]);
        }

        cout << a1 << '\n' << a2 << '\n';
    }
    return 0;
}
