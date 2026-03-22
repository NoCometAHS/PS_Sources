#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r1, r2, c1, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;

    int line = n*2 - 1, mid = line/2;
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            int originR = r % line, originC = c % line;

            int dist = abs(originR - mid) + abs(originC - mid);
            if (dist < n) {
                cout << (char)('a' + dist%26);
            }
            else {
                cout << '.';
            }
        }

        cout << '\n';
    }
    return 0;
}

// 2*n -1