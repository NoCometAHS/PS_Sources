#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        unordered_set<int> seat;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            seat.insert(num);
        } 

        cout << n - seat.size() << '\n';
    }
    return 0;
}
