#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    set<char> ss, tt;
    for (auto& c : s) {
        ss.insert(c);
    }

    for (auto& c : t) {
        tt.insert(c);
    }

    int q;
    cin >> q;

    while (q--) {
        string w;
        cin >> w;

        bool ak = true, tk = true;
        for (auto& ch : w) {
            
            if (!ss.count(ch)) {
                tk = false;
            }

            if (!tt.count(ch)) {
                ak = false;
            }
        }


        if (!(ak ^ tk)) {
            cout << "Unknown\n";
        }
        else if (ak) {
            cout << "Aoki\n";
        }
        else {
            cout << "Takahashi\n";
        }
    }

    return 0;
}
