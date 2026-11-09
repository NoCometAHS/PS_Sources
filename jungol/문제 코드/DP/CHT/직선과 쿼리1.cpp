// 기본 CHT

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<iipair> arr(n);
    for (auto& [a, b] : arr) cin >> a >> b;
    
    sort(arr.begin(), arr.end());

    vector<iipair> convex;
    if (arr.size() > 2) {
        convex.push_back(arr[0]);
        convex.push_back(arr[1]);

        for (int i = 2; i < n; i++) {
            auto& [u, v] = arr[i];

            while (true) {
                if (convex.size() < 2) break;

                auto& [A, B] = convex[convex.size()-2];
                auto& [a, b] = convex.back() ;


                if ((a-u)*(B-b) < (v-b)*(a-A)) convex.pop_back();
                else break;
            }

            if (convex.back().first == arr[i].first) convex.pop_back();
            convex.push_back(arr[i]);
        }

    }
    else {
        swap(convex, arr);
    }


    while (q--) {
        ll x;
        cin >> x;

        int lt = 0, rt = convex.size()-1, m;
        int ansIdx=1;
        while (lt <= rt) {
            m = (lt + rt) / 2;

            if (m == convex.size()-1) {
                ansIdx = m;
                break;
            }
            if (convex[m].first*x + convex[m].second >= convex[m+1].first*x + convex[m+1].second) {
                ansIdx = m;
                rt = m - 1;
            }
            else {
                lt = m + 1;
            }
        }

        cout << convex[ansIdx].first*x + convex[ansIdx].second << '\n';
    }

    return 0;
}