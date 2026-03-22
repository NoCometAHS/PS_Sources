#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int p;
        cin >> p;

        unordered_set<int> chk;
        for (int i = 0; i < p; i++) {
            int num;
            cin >> num;
            chk.insert(num);
        }

        int n;
        cin >> n;

        int bestTime = 1e9, bestNumber, cnt = 0;
        int threshold = 6*60;
        while (n--) {
            int num, h, m;
            cin >> num >> h >> m;

            if (chk.count(num) == 0) continue;

            int time = h*60 + m;

            if (time < 0 || threshold < time ) continue;

            if (bestTime > time) {
                bestTime = time;
                bestNumber = num;
            }
            cnt++;
        }

    cout << bestNumber << ' ' << cnt << '\n';
    }
    return 0;
}
