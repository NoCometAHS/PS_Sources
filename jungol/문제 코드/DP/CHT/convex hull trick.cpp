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
    convex.push_back(arr[0]);
    convex.push_back(arr[1]);

    for (int i = 2; i < n; i++) {
        auto [u, v] = arr[i];

        while (true) {
            if (convex.size() < 2) break;

            auto [A, B] = convex.back();
            auto [a, b] = convex[convex.size()-1];


            if (A*(b-B)+(A-a)*B > u*(b-B)+v*(A-a)) convex.pop_back();
            else break;
        }

        convex.push_back(arr[i]);
    }

    
    while (q--) {
        int x;
        cin >> x;

        int lt = 0, rt = convex.size()-1, m;
        int ansIdx = convex.size()-1;
        while (lt <= rt) {
            m = (lt + rt) / 2;

            if (convex[m].first*x + convex[m].second > convex[m+1].first*x + convex[m+1].second) {
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