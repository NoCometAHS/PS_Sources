#include "bits/stdc++.h"

using namespace std;

using LL =long long;
int main() {
    int N;
    cin >> N;

    unordered_map<string, vector<LL>> items;
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int idx;
        string str;
        cin >> idx >> str;

        items[str].push_back(idx);
    }

    for (auto& [s, v] : items) sort(v.begin(), v.end());

    int M;
    cin >> M;
    vector<string> order;
    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;

        order.push_back(tmp);
    }




    map<int, LL> dp;
    for (auto& i : items[order.front()]) {
        dp.emplace(i, 1);
    }

    for (int i = 1; i < order.size(); i++) {
        map<int, LL> tmp;
        LL sum = 0;
        map<int, LL>::iterator it = dp.begin();

        for (auto& idx : items[order[i]]) {
            while (it != dp.end() && it->first <= idx) {
                sum += it->second;
                it++;
            }

            tmp[idx] = sum;
        }

        swap(tmp, dp);
    }

    int ans = 0;
    for (auto& [i,v] : dp) ans += v;
    
    if (ans == 0) cout << "impossible";
    else if (ans == 1) cout << "unique";
    else cout << "ambiguous";
    

    return 0;
}