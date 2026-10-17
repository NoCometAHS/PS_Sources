#include "bits/stdc++.h"

using namespace std;
using LL = int;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t= 4;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> arr(m);
        vector<vector<int>> order(n+1);

        int idx = 0;
        for (auto& i : arr) {
            cin >> i;

            order[i].push_back(idx++);
        }

        for (auto& v : order) reverse(v.begin(), v.end());


        bool flag = true;
        vector<int> ans;
        priority_queue<iipair, vector<iipair>, greater<iipair>> pq;
        vector<bool> watered(n+1, true);

        for (int i = 1; i <= n; i++) {
            if (order[i].empty()) continue;
            pq.emplace(order[i].back(), i);
        }

        for (int i = 0; i < m; i++) {
            if (arr[i]) {
                if (watered[arr[i]]) {
                    flag = false;
                    break;
                }

                watered[arr[i]] = true;
                order[arr[i]].pop_back();
                if (!order[arr[i]].empty())  pq.emplace(order[arr[i]].back(), arr[i]);
            }
            else {
                if (pq.empty()) {
                    ans.push_back(0);
                    continue;
                }

                auto [pos, id] = pq.top();
                pq.pop();

                ans.push_back(id);
                watered[id] = false; 
            }


        }

        if (flag) {
            cout << "YES\n";
            for (auto&  i : ans) cout << i << ' ';
            cout << '\n';
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}