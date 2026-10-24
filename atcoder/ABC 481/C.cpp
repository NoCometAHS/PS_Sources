#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;

    unordered_map<string, int> ac;

    while (q--) {
        string t;
        cin >> t;

        if (ac.count(t)) {
            cout << ac[t] << '\n';
        }
        else {
            ac.emplace(t, ac.size()+1);
            cout << ac.size() << '\n';
        }
    }


    return 0;
}