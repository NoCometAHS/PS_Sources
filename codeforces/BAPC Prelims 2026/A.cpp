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
    
    map<string, string> dict;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        string word = str;
        vector<int> ypos;
        int pos = 0;
        for (auto& ch : word) {
            if (ch == 'i' or ch == 'e' or ch == 'o' or ch == 'u') ch = 'a';
            if (ch == 'y') ypos.push_back(pos);

            pos++;
        }


        for (int i = 0; i < (1 << ypos.size()); i++) {
            string temp = word;

            for (int k = 0; k < ypos.size(); k++) {
                if ((i >> k) & 1) {
                    temp[ypos[k]] = 'a';
                }
            }

            if (dict.count(temp)) {
                dict[temp] = "-";
            }
            else {
                dict[temp] = str;
            }
        }
    }

    while (m--) {
        int q;
        cin >> q;

        vector<string> ans;
        string status("possible");

        while (q--) {
            string a;
            cin >> a;

            if (dict.count(a) == 0) {
                status = "impossible";
                continue;
            }
            else if (status.front() == 'p' and dict[a] == "-") {
                status = "ambiguous";
                continue;
            }
            else {
                ans.push_back(dict[a]);
            }
        }

        if (status.front() != 'p') {
            cout << status << '\n';
        }
        else {
            cout << status << ' ';
            for (auto& i : ans) cout << i << ' ';
            cout << '\n';
        }
    }
    

    

    return 0;
}