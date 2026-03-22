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
    vector<pair<string, int>> algo(n);
    for (auto& [s, i] : algo) cin >> s >> i;
    sort(algo.begin(), algo.end());

    int m;
    cin >> m;

    map<string, pair<int, int>> loveAlgo;
    for (int i = 0; i < m; i++) {
        string name;
        int t;
        cin >> name >> t;

        int first = 0, second = 1;
        if (abs(algo[first].second - t) > abs(algo[second].second - t)) {
            swap(first, second);
        }

        for (int k = 2; k < n; k++) {
            int cur = k;
            int firstD = abs(algo[first].second - t);
            int secondD = abs(algo[second].second - t);

            int d = abs(algo[cur].second - t);
            if (d < firstD) {
                swap(first, cur);
            }

            d = abs(algo[cur].second - t);
            if (d < secondD){
                second = cur;
            }
            else if (d == secondD) {
                if (algo[cur].first < algo[second].first) {
                    second = cur;
                }
            }
        }

        loveAlgo[name] = {first, second};
    }

    int qCnt;
    cin >> qCnt;
    cin.ignore();

    string cur;
    while (qCnt--) {
        string q;
        getline(cin, q);

        stringstream ss(q);
        
        if (q.back() == '!') {
            ss >> cur;
            cout << "hai!\n";
        }
        else {
            cout << algo[loveAlgo[cur].second].first << " yori mo " << algo[loveAlgo[cur].first].first << '\n';
        }
    }
    return 0;
}
