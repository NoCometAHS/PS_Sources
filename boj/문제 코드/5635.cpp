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

    vector<tuple<int, int, int, string>> arr(n);

    for (auto& [year, month, day, name] : arr) {
        cin >> name >> day >> month >> year;
    }

    sort(arr.begin(), arr.end());

    cout << get<3>(arr.back()) << '\n' << get<3>(arr.front());
    return 0;
}
