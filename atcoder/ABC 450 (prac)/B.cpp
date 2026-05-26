#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    LL graph[101][101] = {0,};

    for (int i = 1; i < n; i++) {
        for (int k = i + 1; k <= n; k++) {
            cin >> graph[i][k];
            graph[k][i] = graph[i][k];
        }
    }

    bool ans = false;
    for (int i = 1; i <= n; i++) {
        for (int k = i+1; k <= n; k++) {
            for (int p = k+1; p <= n; p++) {
                ans |= graph[i][k] + graph[k][p] < graph[i][p];
            }
        }
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}
