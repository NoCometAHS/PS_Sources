#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    int odd = 0;
    vector<int> arr(n);
    for (auto& i : arr) {
        cin >> i;
        odd += i % 2;
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    odd -= odd % 2;
    while (!arr.empty()) {
        int cur = arr.back();
        arr.pop_back();

        if (cur % 2) {
            if (odd) {
                odd--;
                ans += cur;
            }
        }
        else {
            ans += cur;
        }
        
    }

    cout << ans;
    return 0;
}