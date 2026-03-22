#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int arr[26] = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int aL, bL;
    string a, b;
    cin >> aL >> bL >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> ans;
    for (int i = 0; !a.empty() && !b.empty(); i++) {
        ans.push_back(arr[a.back()-'A']);
        ans.push_back(arr[b.back()-'A']);

        a.pop_back();
        b.pop_back();
    }

    while (!a.empty()) {
        ans.push_back(arr[a.back()-'A']);
        
        a.pop_back();
    }

    while (!b.empty()) {
        ans.push_back(arr[b.back()-'A']);
        
        b.pop_back();
    }

    vector<int> temp(ans.size());
    for (int k = 0; k < ans.size() - 2; k++) {
        for (int i = 0; i < ans.size() - 1; i++) {
            temp[i] = (ans[i] + ans[i+1]) % 10;
        }

        swap(temp, ans);
    }

    if (ans[0] == 0) cout << ans[1] << '%';
    else cout << ans[0] << ans[1] << '%';

    return 0;
}
