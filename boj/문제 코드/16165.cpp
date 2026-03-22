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

    unordered_map<string, vector<string>> teams;
    unordered_map<string, string> members;

    while (n--) {
        string team;
        cin >> team;

        int c;
        cin >> c;
        while (c--) {
            string name;
            cin >> name;

            teams[team].push_back(name);
            members[name] = team;
        }
    }

    for (auto& [s, v] : teams) {
        sort(v.begin(), v.end());
    }

    while (m--) {
        string s;
        int q;
        cin >> s >> q;

        if (q) {
            cout << members[s] << '\n';
        }
        else {
            for (auto& a : teams[s]) cout << a << '\n';
        }
    }
    return 0;
}
