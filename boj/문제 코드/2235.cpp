#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;


string dfs(int cur, vector<string>& dp, const string& ency, const string& pmt) {
    if (cur == ency.length()) return "";
    if (!dp[cur].empty()) return dp[cur];

    string ret1 = pmt[ency[cur] - '0'] + dfs(cur+1, dp, ency, pmt);
    string ret2;

    if (cur + 1 < ency.length()) {
        string num = string{ency[cur]} + ency[cur+1];
        int IntNum = stoi(num);
        
        if (IntNum < 26) {
            ret2 = pmt[IntNum] + dfs(cur+2, dp, ency, pmt);
        }
        else ret2 = string(50, 'a');
    }
    else {
        return dp[cur] = ret1;
    }


    if (ret1.length() == ret2.length()) {
        return dp[cur] = (ret1 < ret2 ? ret2 : ret1);
    }
    return dp[cur] = (ret1.length() < ret2.length() ? ret1 : ret2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string pmt;
    cin >> pmt;

    int tc = 1;
    while (pmt != "#") {
        string enc;
        cin >> enc;

        cout << "Problem " << tc++ << '\n';
        while (enc != "0") {
            vector<string> dp(enc.length());
            
            cout << dfs(0, dp, enc, pmt) << '\n';

            cin >> enc;
        }

        cout << '\n';

        cin >> pmt;
    }
    return 0;
}

/*
사전적으로 가장 큰 짧은 놈이면

앞에서부터 큰 숫자로 가져가 줘야 하고, -> 숫자 큰게 무조건 사전순으로 큰게 아니네.

이건 dp로 가장 짧은 거 구할 떄, 알아서 되는 거 아닌가?

dp[i] : 가장 사전적으로 큰거 i까지 완성했을 떄의 최소 길이
문자열로 할 땐, 가까운 얘들로 보면 될 듯.

dp[i] = min(dp[i-1], dp[i-2]{단, 25 안 일 때}) + 1


0 0 

지금 코드는 앞을 크게 해야하는데, 자기 자신을 크게 하니깐 문제가 생기지.
---
백트레킹 하면 좋기 ㄴ하겠네
*/