#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<iipair> st;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        while (!st.empty() && st.top().first <= h) st.pop();

        if (st.empty()) cout << "-1\n";
        else cout << st.top().second << '\n';

        st.emplace(h, i+1);
    }

    return 0;
}