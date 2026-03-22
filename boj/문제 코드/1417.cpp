#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, me;
    cin >> n >> me;

    priority_queue<int> pq;
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }
    
    int ans = 0;
    while (!pq.empty() && pq.top() >= me) {
        int t = pq.top();
        pq.pop();

        ans++;
        me++;
        t--;

        pq.push(t);
    }

    cout << ans;
    return 0;
}
