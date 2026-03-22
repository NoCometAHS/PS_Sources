#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> psum(2, 0);
    psum[1] = 1;

    for (int i = 0; i < n; i++) {
        int q, x, y;
        cin >> q >> x >> y;

        int sum = psum[y] - psum[x-1];
        if (q == 1) {
            if (sum == y - x + 1) {
                cout << "Yes\n";
                psum.push_back(psum.back() + 1);
            }
            else {
                cout << "No\n";
                psum.push_back(psum.back());
            }
        }
        else {
            if (sum == 0) {
                cout << "Yes\n";
                psum.push_back(psum.back() + 1);
            }
            else {
                cout << "No\n";
                psum.push_back(psum.back());
            }
        }
    }
    return 0;
}
