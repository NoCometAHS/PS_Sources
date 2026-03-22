#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<char> a;
    string str;
    getline(cin, str);
    while (str != "*") {
        for (auto& i : str) {
            if (i ==' ') continue;
            a.insert(i);
        }

        if (a.size() == 26) {
            cout << "Y\n";
        }
        else {
            cout << "N\n";
        }

        getline(cin, str);
        a.clear();
    }
    return 0;
}
