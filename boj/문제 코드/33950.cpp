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

    while (n--) {
        string str;
        cin >> str;

        string ans;
        for (auto& i : str) {
            if (!ans.empty() && ans.back() == 'P' && i == 'O')  {
                ans.push_back('H');
            }

            ans.push_back(i);
        }

        cout << ans << '\n';
    }
    return 0;
}
