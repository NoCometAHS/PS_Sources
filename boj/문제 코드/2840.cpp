#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<char> ans(n, '?');
    unordered_set<char> chk;

    int cur = 0;
    bool flag = false;
    for (int i = 0; i < m; i++) {
        int num;
        char ch;
        cin >> num >> ch;

        cur = (cur + num) % n;

        if ((ans[cur] != '?' && ans[cur] != ch) || (ans[cur] == '?' && chk.count(ch))) {
            flag = true; 
            break;
        }
        
        chk.insert(ch);
        ans[cur] = ch;
    }

    if (flag) cout << "!";
    else {
        for (int i = 0; i < n; i++, cur = (cur - 1 + n)%n) {
            cout << ans[cur];
        }
    }
    return 0;
}
