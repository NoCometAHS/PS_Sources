#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int n, m;
void dfs(vector<int>& arr, int depth) {
    static vector<int> output;
    if (depth == m) {
        for (auto& i : output) cout << i << ' ';
        cout << '\n';

        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        output.push_back(arr[i]);
        dfs(arr, depth+1);
        output.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    dfs(arr, 0);
    return 0;
}
