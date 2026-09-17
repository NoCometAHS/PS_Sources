#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    int n;
    cin >> n;


    int ans = 0;
    vector<bool> close(n+1, false);
    for (int i = 1; i <= n; i++) {
        for (int k = i+1; k <= n; k++) {
            if (close[k]) {
                ans ++;
                continue;
            }

            string res;
            cout << "? " << i << " " << k << endl;
            cin >> res;


            if (res == "Yes") {
                close[k] = true;
                ans++;
            }
            else {
                break;
            }
        }
    }    

    cout << "! " << ans << endl;

    return 0;
}

// ac후 01:14 남았음