#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char w;
    int n;
    cin >> w >>n;

    TwoVector<char> arr(n, vector<char>(n));
    for (auto& v : arr) {
        for (auto& i : v) cin >> i;
    }
    
    map<char, char> ud{{'1', '1'}, {'2', '5'}, {'3', '?'}, {'4', '?'},{'5', '2'},{'6', '?'},{'7', '?'}, {'8', '8'},{'9', '?'}};
    if (w == 'U' || w == 'D') {
        for (int i = 0; i < n; i++) {
            for (int u = 0, d = n-1; u < d; u++, d--) {
                swap(arr[u][i], arr[d][i]);
            }
        }

        for (auto& v : arr) {
            for (auto& i : v) {
                cout << ud[i] << ' ';
            }
            cout << '\n';
        }

    }   
    else {
        for (auto& v : arr) {
            reverse(v.begin(), v.end());
            for (auto& i : v) {
                cout << ud[i] << ' ';
            }
            cout << '\n';
        }
    } 
    return 0;
}
