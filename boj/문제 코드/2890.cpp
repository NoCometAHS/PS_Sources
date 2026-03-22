#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;

    string str;
    vector<int> dist(10, 0);

    for (int i = 0; i < r; i++) {
        cin >> str;

        for (int k = 1; k < c - 1; k++) {
            if (str[k] == '.') continue;

            dist[str[k] - '0'] = k;
            break;
        }
    }

    vector<int> sorted(dist);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    

    for (int i = 1; i <= 9; i++) {
        dist[i] = sorted.end() - lower_bound(sorted.begin(), sorted.end(), dist[i]);
    }

    for (int i = 1; i < 10; i++) cout << dist[i] << '\n';
    return 0;
}
