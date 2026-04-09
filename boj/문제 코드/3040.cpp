#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> arr(9);
    for (auto& i : arr) cin >> i;

    vector<int> order(7, 1);
    order.resize(9);

    do {
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            if (!order[i]) continue;

            sum += arr[i];
        }

        if (sum == 100) {
            for (int i = 0; i < 9; i++) if (order[i]) cout << arr[i] << "\n";
            break;
        }

    }while (prev_permutation(order.begin(), order.end()));

    
    return 0;
}