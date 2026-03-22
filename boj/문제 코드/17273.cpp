#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int arr[2];
    cin >> arr[0] >> arr[1];

    int cur = 0;
    while (m--) {
        int num;
        cin >> num;

        if (arr[cur] <= num) {
            cur = (cur + 1) % 2;
        }
    }

    cout << arr[cur];
    return 0;
}
