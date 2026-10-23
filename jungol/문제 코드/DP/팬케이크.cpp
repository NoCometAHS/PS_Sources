#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dp[2<<21];

int encode(const string& str){
    int ret = 0;
    for (auto& i: str) {
        ret = ret*3 + i - 'A';
    }

    return ret;
}

string decode(int code, int len) {
    string ret;

    for (int i = 0; i < len; i++) {
        ret.push_back(code % 3 + 'A');
        code /= 3;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

void bfs(string status) {
    dp[encode(status)] = 0;

    queue<int> que;
    que.push(encode(status));

    while (!que.empty()) {
        int curCode = que.front();
        que.pop();
        string next(decode(curCode, status.length()));
        for (int i = 2; i <= status.length(); i++) {    
            reverse(next.begin(), next.begin()+i);

            int nextCode = encode(next);

            if (dp[nextCode] == -1) {
                que.push(nextCode);
                dp[nextCode] = dp[curCode] + 1;
            }

            reverse(next.begin(), next.begin()+i);
        }
    }
}

void FindCandidate(int len, int pre = 0, string cur = "") {
    if (len == 0) {
        bfs(cur);
        return;
    }

    cur += 'A' + pre;
    for (int i = pre; i < 3; i++) {
        FindCandidate(len-1, i, cur);
        cur.back() += 1;
    }
    cur.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));

    int n, q;
    cin >> n >> q;

    FindCandidate(n);

    while (q--) {
        string str;
        cin >> str;

        cout << dp[encode(str)] << '\n';
    }

    
    return 0;
}