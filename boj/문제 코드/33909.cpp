#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s, c, o, n;
    cin >> s >> c >> o >> n;

    int ans = 0;
    while (true) {
        while (s < 2) {
            if (n <= 0) {
                break;
            }
            
            n--;
            s++;
        }

        while (c < 4) {
            if (o <= 0) {
                break;
            }

            o--;
            c += 2;
        }


        while (o < 1) {
            if (c < 2) {
                break;
            }

            c -= 2;
            o++;
        }

        while (n < 1) {
            if (s <= 0) {
                break;
            }

            s--;
            n++;
        }


        if (s < 2 || c < 4 || o < 1 || n < 1) {
            break;
        }
        s -= 2;
        c -= 4;
        o -= 1;
        n -= 1;

        ans++;

    }

    cout << ans;

    return 0;
}
