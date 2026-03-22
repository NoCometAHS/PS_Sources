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

    using brick = tuple<int,int,int,int>;
    vector<brick> arr(n);


    int index = 1;
    for (auto& [area, weigth, height, num] : arr) {
        cin >> area >> height >> weigth;
        num = index++;
    }

    sort(arr.begin(), arr.end(), greater<>());
    
    vector<int> dp(n, 0), pre(n, -1);
    dp[0] = get<2>(arr[0]);
    
    int mxIndex = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = get<2>(arr[i]);

        for (int k = 0; k < i; k++) {
            if (get<1>(arr[k]) < get<1>(arr[i])) continue;

            int height = dp[k] + get<2>(arr[i]);
            if (dp[i] < height) {
                dp[i] = height;    
                pre[i] = k;
            }

            if (dp[mxIndex] < dp[i]) mxIndex = i;
        }
    }

    vector<int> ans;
    while (mxIndex != -1) {
        ans.push_back(get<3>(arr[mxIndex]));
        mxIndex = pre[mxIndex];
    }

    cout << ans.size() << '\n';
    for (auto& i : ans) cout << i << '\n';


    return 0;
}

/*
dp[i] i블럭을 마지막에 썼을 때의 가장 높은 높이.

dp[i] = max(dp[1 ~ i-1] 하지만 무게가 되는 것들에서만) + height[i];

정렬된 상태에서 i ~ n은 밑넓이가 좁아서 무조건 못 써. 

*/