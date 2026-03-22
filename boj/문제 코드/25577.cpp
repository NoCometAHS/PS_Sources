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

    vector<int> arr(n), sorted;
    for (auto& i : arr) {
        cin >> i;
        sorted.push_back(i);
    }
    sort(sorted.begin(), sorted.end());

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
    }

    vector<bool> chk(n, false);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;

        c++;
        int cur = i;
        while (!chk[cur]) {
            chk[cur] = true;
            cur = p[cur];
        }
    }

    cout << n - c;
    return 0;
}
