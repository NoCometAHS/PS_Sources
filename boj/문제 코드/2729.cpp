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
        string a, b;

        cin >> a >> b;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        a.resize(88, '0');
        b.resize(88, '0');
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans;
        int up = 0;
        for (int i = a.length()-1; i >= 0; i--) {
            int v = a[i] - '0', u = b[i] - '0';

            if (v + u + up >= 2) {
                ans.push_back('0' + (v+u+up) % 2);
                up = 1;
            }
            else {
                ans.push_back('0' + v + u + up);
                up = 0;
            }
        }
        
        while (ans.length() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());

        cout << ans << '\n';
    }
    return 0;
}
