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

    vector<int> arr(n + 1, -1);
    int mx = 0;
    for (int i = 0; i < n*2; i++) {
        int num;
        cin >> num;

        if (arr[num] == -1) {
            arr[num] = i;
        }
        else {
            int cnt = i - arr[num] - 1;

            mx = max(mx, cnt);
        }
    }

    cout << mx;
    return 0;
}
