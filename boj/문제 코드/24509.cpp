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

    vector<vector<iipair>> arr(4);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        for (int k = 0; k < 4; k++) {
            int sc;
            cin >> sc;

            arr[k].emplace_back(sc, num);
        }
    }

    vector<bool> chk(n, false);
    for (auto& v : arr) {
        sort(v.begin(), v.end(), [](iipair a, iipair b){
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        for (auto& [sc, num] : v) {
            if (chk[num-1]) continue;
            
            chk[num-1] = true;
            cout << num << ' ';
            break;
        }
    }

    return 0;
}
