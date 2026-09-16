#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<vector<char>> votes(n, vector<char>(m));
    for (auto& i : votes) for (auto& k : i) cin >> k;


    vector<int> points(n, 0);
    for (int i = 0; i < m; i++) {
        int cnt[2] = {0,};
        for (int k = 0; k < n; k++) {
            cnt[votes[k][i] - '0']++;
        }

        if (cnt[0] == 0 || cnt[1] == 0) {
            for (auto& i : points) i++;
        } 

        char whoWin = (cnt[0] > cnt[1]) + '0';

        for (int k = 0; k < n; k++) {
            if (votes[k][i] != whoWin) continue;

            points[k]++;
        }
    }

    int mx = -1;
    for (auto& i : points) mx = max(mx, i);

    for (int i = 0; i < n; i++) {
        if (points[i] == mx) {
            cout << i + 1 << ' '; 
        }
    }
    
    return 0;
}


/*
n은 홀수.
m번 투표.

어떤 투표에서 몰표가 나왔으면 모두에게 1점.
수가 더 적으면 1점.

*/