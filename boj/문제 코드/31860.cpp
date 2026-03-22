#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, t;
    cin >> n >> a >> t;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        pq.push(num);
    }

    int mood = 0;

    vector<int> ans;
    
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        mood = mood/2 + cur;
        ans.push_back(mood);

        cur -= a;

        if (cur > t) {
            pq.push(cur);
        }
    }

    cout << ans.size() << '\n';
    for (auto& i : ans) {
        cout << i << '\n';
    }


    return 0;
}
