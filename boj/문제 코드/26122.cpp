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
    string str;
    cin >> n >> str;
    
    vector<pair<char, int>> arr;
    arr.emplace_back(str.front(), 1);
    for (int i = 1; i < n; i++) {
        if (arr.back().first == str[i]) {
            arr.back().second++;
        }
        else {
            arr.emplace_back(str[i], 1);
        }
    }

    int ans = 0;
    for (int i = 1; i < arr.size(); i++) {
        ans = max(ans, min(arr[i-1].second, arr[i].second)*2);
    }

    cout << ans;
    return 0;
}

/*
다른 문자열 나오면 앞에 남아있어도 버려야 하네.

큐가지고 쉽게 할 수 있을 듯? 아닌가
*/