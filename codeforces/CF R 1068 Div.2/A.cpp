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
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        int ans = 0;
        int count = 0;
        for (auto& i : str) {
            if (i == '1') {
                count = k;
            }
            else {
                if (count == 0) ans++;
                else count--;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}