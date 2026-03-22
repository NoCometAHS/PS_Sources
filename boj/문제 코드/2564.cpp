#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int oppo[5] = {0, 2, 1, 4, 3};
int n, m;
int shortLen(int side1, int pos1, int side2, int pos2) {
    if (side1 == side2) {
        return abs(pos1 - pos2);
    }
    if (oppo[side1] == side2) {
        return min(pos1 + pos2, 2*n - pos1 - pos2) + (side1 <= 2 ? m : n);
    }
    else {
        if (side1 == 1) {
            if (side2 == 3) {
                return pos1 + pos2;
            }
            else {
                return n - pos1 + pos2;
            }
        }
        else if (side1 == 2) {
            if (side2 == 3) {
                return pos1 + m - pos2;
            }
            else {
                return n - pos1 + m - pos2;
            }
        }
        else if (side1 == 3) {
            if (side2 == 1) {
                return pos1 + pos2;
            }
            else {
                return m - pos1 + pos2;
            }
        }
        else {
            if (side2 == 1) {
                return pos1 + n - pos2;
            }
            else {
                return m - pos1 + n - pos2;
            }
        }

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    int q;
    cin >> q;

    vector<iipair> query(q);
    for (auto& [s, p] : query) cin >> s >> p;

    int curS, curP;
    cin >> curS >> curP;

    int ans = 0;
    for (auto& [s, p] : query) {
        ans += shortLen(curS, curP, s, p);
    }

    cout << ans;
    
    return 0;
}
