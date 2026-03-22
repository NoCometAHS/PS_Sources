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

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        vector<int> nums(7, 0);
        for (int i = 0; i < 4; i++) {
            int num;
            cin >> num;
            nums[num]++;
        }

        int mx;
        vector<int> twoNums;
        for (int i = 1; i <= 6; i++) {
            if (nums[i]) mx = i;

            if (nums[i] == 4) {
                sum = 50000 + i * 5000;
            }
            else if (nums[i] == 3) {
                sum = 10000 + i * 1000;
            }
            else if (nums[i] == 2) {
                twoNums.push_back(i);
            }
        }

        if (!sum) {
            if (twoNums.size() == 2) {
                sum = 2000 + twoNums.front() * 500 + twoNums.back() * 500;
            }
            else if (twoNums.size() == 1) {
                sum = 1000 + twoNums.front() * 100;
            }
            else {
                sum = mx * 100;
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
