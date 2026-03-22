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

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;
    
    int from, to;
    cin >> from >> to;
    from--, to--;

    if (from == to) {
        cout << 0;
        return 0;
    }

    vector<int> dist(n, 1e9);
    queue<int> que;
    
    que.push(from);
    dist[from] = 0;

    int ans = 1e9;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = cur + arr[cur]; i < n; i += arr[cur]) {
            if (i == to) {
                ans = dist[cur] + 1;
                break;
            }
            

            if (dist[i] == 1e9) {
                que.push(i);
                dist[i] = dist[cur] + 1;
            }
        }

        for (int i = cur - arr[cur]; i >= 0; i -= arr[cur]) {
            if (i == to) {
                ans = dist[cur] + 1;
                break;
            }
            
            if (dist[i] == 1e9) {
                que.push(i);
                dist[i] = dist[cur] + 1;
            }
        }

        if (ans != 1e9) break;
    }

    cout << (ans == 1e9? -1 : ans);
    return 0;
}
