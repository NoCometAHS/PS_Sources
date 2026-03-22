#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n, b, m;
    

    while (cin >> n >> b >> m) {
        int ans = 0;
        
        while (n <= m) {
            n += n * b / 100;
            ans++;
        }
        
        cout << ans << '\n';
    }

 
    return 0;
}
