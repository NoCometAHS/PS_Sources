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


    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        ans = max(ans, num);
    } 

    cout << ans;
    return 0;
}
