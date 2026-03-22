#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

set<string> ans;

void dfs(int cur, string& str, vector<iipair>& arr) {
    if (cur == arr.size()) {
        string res;
        for (auto& ch : str) {
            if (!ch) continue;
            res += ch;
        }
        ans.insert(res);
        return;
    }

    auto [l, r] = arr[cur];
    
    str[l] = str[r] = 0;

    dfs(cur+1, str, arr);

    str[l] = '(';
    str[r] = ')';
    
    dfs(cur+1, str, arr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    stack<int> st;
    vector<iipair> arr;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            st.push(arr.size());
            arr.emplace_back(i, 0);
        }
        else if (str[i] == ')') {
            int idx = st.top();
            st.pop();
            arr[idx].second = i;
        }
    }

    reverse(arr.begin(), arr.end());

    dfs(0, str, arr);
    ans.erase(ans.begin());
    
    for (auto& s : ans) {
        cout << s << '\n';
    }

    return 0;
}


/*
시작 괄호가 가장 뒤에 있는 괄호 먼저 제거하기?

스택으로 뭐가 쌍인지는 쉽게 알 수 있어.


*/