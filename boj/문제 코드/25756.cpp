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

    double ans = 0;
    while (n--) {
        int p;
        cin >> p;  
        
        ans = 1.0 - (1 - ans) * (1.0 - p/100.0);
        cout << fixed;
        cout.precision(6);

        cout << ans * 100<< '\n';
    }
    return 0;
}
