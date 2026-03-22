#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> cur(4), needed(4);
    for (auto& i : cur) cin >> i;
    for (auto& i : needed) cin >> i;

    int t;
    cin >> t;

    int cookies = 0;
    while (t--) {
        int q, a;
        cin >> q >> a;

        switch(q) {
        case 1 :
            {
                bool flag = true;
                for (int i = 0; i < 4; i++) {
                    if (cur[i] < needed[i] * a) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    for (int i = 0; i < 4; i++) cur[i] -= needed[i] * a;
                    cookies += a;

                    cout << cookies << '\n';
                }
                else {
                    cout << "Hello, siumii\n";
                }
            }
            break;

        case 2 :
            cur[0] += a;
            cout << cur[0] << '\n';
            break;

        case 3 :
            cur[1] += a;
            cout << cur[1] << '\n';
            break;

        case 4 :
            cur[2] += a;
            cout << cur[2] << '\n';
            break;
            
        case 5 :
            cur[3] += a;
            cout << cur[3] << '\n';
            break;
        }
    }

    return 0;
}
