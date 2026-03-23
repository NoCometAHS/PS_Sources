#include "bits/stdc++.h"

using namespace std;
using LL = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        int r,c;
        cin >> r >> c;

        if (r == 136) ans += 1000;
        else if (r== 142) ans += 5000;
        else if (r == 148) ans += 10000;
        else ans += 50000;
    }

    cout << ans;
    
    return 0;
}