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
        int n;
        string str;
        cin >> n >> str;

        int ans = 1e9;
        bool f = true;
        for (int i = 0; i < str.length() - 3; i++) {
            int ret = 0;
            if (str[i] != '2') ret++;
            if (str[i+1] != '0') ret++;
            if (str[i+2] != '2') ret++;
            if (str[i+3] != '6') ret++;

            ans = min(ans, ret);

            
            if (str[i] == '2') if (str[i+1] == '0') if (str[i+2] == '2') if (str[i+3] == '5') 
                f = false; 
        }

        if (f) ans = 0;
        cout << ans << '\n';
    }
    return 0;
}