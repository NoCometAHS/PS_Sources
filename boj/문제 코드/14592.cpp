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
    vector<tuple<int,int,int,int>> arr(n);
    for (int i = 1; i <= n; i++) {
        auto& [num, sco, sub, tim] = arr[i-1];
        num = i;
        cin >> sco >> sub >> tim;
    }

    sort(arr.begin(), arr.end(), [](tuple<int,int,int,int> a, tuple<int,int,int,int> b) {
        auto& [num1, sco1, sub1, tim1] = a;
        auto& [num2, sco2, sub2, tim2] = b;

        if (sco1 == sco2) {
            if (sub1 == sub2) {
                return tim1 < tim2;
            }
            return sub1 < sub2;
        }
        return sco1 > sco2;
    });

    cout << get<0>(arr.front());

    return 0;
}
