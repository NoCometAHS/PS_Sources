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
    
    while (n--) {
        string inp;
        getline(cin, inp);

        stringstream ss(inp);

        vector<string> ans;
        string str;

        while (ss >> str) {
            ans.push_back(str);
        }

        ans.push_back(ans.front());
        ans.erase(ans.begin());

        ans.push_back(ans.front());
        ans.erase(ans.begin());

        for (auto& i: ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
