#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string key, origin;;
    cin >> key >> origin;
    
    
    vector<string> code(key.length());
    int fragLength = origin.length() / key.length();
    for (int k = 0; k < key.length(); k++) {
        for (int i = 0; i < fragLength; i++) {
            code[k].push_back(origin[k*fragLength + i]);
        }
    }

    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    map<char, int> order;
    vector<string> ans;
    for (int i = 0; i < key.length(); i++) {
        int idx = lower_bound(sortedKey.begin(), sortedKey.end(), key[i]) - sortedKey.begin() + order[key[i]];

        order[key[i]]++;

        ans.push_back(code[idx]);
    }

    for (int i = 0; i < fragLength; i++) {
        for (int k = 0; k < key.length(); k++) {
            cout << ans[k][i];
        }
    }
    return 0;
}
