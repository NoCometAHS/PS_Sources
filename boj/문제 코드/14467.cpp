#include "bits/stdc++.h"

using namespace std;

int main(){
    int tc;
    cin >> tc;
    
    map<int,int> mm;
    int ans = 0;
    while (tc--) {
        int c, t;
        cin >> c >> t;

        if (mm.count(c)) {
            ans += mm[c] != t;
            mm[c] = t;
        }
        else {
            mm[c] = t;
        }
    }

    cout << ans;
    return 0;
}