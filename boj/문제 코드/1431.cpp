#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

struct serial{
    string origin;
    int numberSum;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<serial> arr;
    while (n--) {
        string str;
        cin >> str;

        int sum = 0;
        for (auto& ch : str) {
            if (ch < '0' || '9' < ch ) continue;
            sum += ch - '0';
        }

        arr.push_back({str, sum});
    }

    sort(arr.begin(), arr.end(), [](serial& a, serial& b) {
        if (a.origin.length() == b.origin.length()) {
            if (a.numberSum == b.numberSum) return a.origin < b.origin;
            return a.numberSum < b.numberSum;
        }
        return a.origin.length() < b.origin.length();
    });

    for (auto& [s, i] : arr) {
        cout << s << '\n';
    }
    return 0;
}
