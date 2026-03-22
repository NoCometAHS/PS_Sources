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

    using ispair = pair<int, string>;
    vector<ispair> words(n);
    for (auto& [a, b] : words) {
        cin >> b >> a;
    }

    sort(words.begin(), words.end(), greater<ispair>());

    TwoVector<string> ans(4);
    for (int i = 0; i < 4; i++) {
        for (int k = i; k < n; k += 4) {
            ans[i].push_back(words[k].second);
        }
    }    

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ' ';
        
        sort(ans[i].begin(), ans[i].end());

        for (auto& s : ans[i]) {
            cout << s << ' ';
        }
        cout << '\n';
    }    


    return 0;
}
