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
        cin >> n;
        
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            if (st.empty() || st.top() <= num) st.push(num);
            else ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}