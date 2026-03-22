#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL h, m, s;
    cin >> h >> m >>s;

    LL sec = h*3600 + m * 60 + s;

    int tc;
    cin >> tc;

    LL sum = 0;
    while (tc--) {
        LL t, a;
        cin >> t;

        if (t == 1){
            cin >> a;
            sum += a;
        } 
        else if (t == 2) {
            cin >> a;
            sum -= a;
        }
        else {
            sec += sum;
            sum = 0;

            while (sec < 0) {
                sec += 24*3600;
            }

            cout << (sec / 3600)%24 << ' ' << (sec/60)%60 << ' ' << sec % 60 << '\n';
        }
    }


    return 0;
}
