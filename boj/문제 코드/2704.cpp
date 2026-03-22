#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);

        for (int i = 5; i >= 0; i--) {
            cout << ((h>>i) & 1) << ((m>>i) & 1) << ((s>>i) & 1);
        }
        cout << ' ';

        for (int i = 5; i >= 0; i--) {
            cout << ((h>>i) & 1);
        }
        for (int i = 5; i >= 0; i--) {
            cout << ((m>>i) & 1);
        }
        for (int i = 5; i >= 0; i--) {
            cout << ((s>>i) & 1);
        }
        cout << "\n";
    }


    return 0;
}
