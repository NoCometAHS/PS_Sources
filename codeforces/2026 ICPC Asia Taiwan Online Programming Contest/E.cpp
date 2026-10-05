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

    TwoVector<int> arr(n, vector<int>(n));
    for (auto& v: arr) for (auto& i : v) cin >> i;


    bool flag = true;

    vector<pair<int, pair<int, int>>> red, blue;
    for (int i = 0; i < n; i++) {       // 대각선 이동 확인하는 부분
        for (int k = 0; k < n; k++) {
            int cur = arr[i][k];
            int orix = (cur-1) % n, oriy = (cur-1) / n;
            
            if (i - oriy and k - orix) flag = false;
            else {
                if (i - oriy) blue.emplace_back(k, pair<int,int>(i, oriy));//높이, 어디서 어디로 움직이는 지 저장
                else if (k - orix) {
                    red.emplace_back(i, pair<int,int>(k, orix));//높이, 어디서 어디로 움직이는 지 저장
                }
            }
        }
    }

    
    for (int i = 0; i < blue.size() - 1; i++) { // 같은 열에서 이동시 겹치는 지 확인
        int k = i+1

        int st = blue[i].second.first, en = blue[i].second.second;
        int dir1 = st - en;

        int from = blue[k].second.first, to = blue[k].second.second;
        int dir2 = from - to;

        if (blue[i].first != blue[k].first) continue;
        if (en < from or to < st) continue;
        if (dir1 * dir2 < 0) flag = false;
    }


    for (int i = 0; i < red.size() - 1; i++) { // 같은 행에서 이동시 겹치는 지 확인
        int k = i+1;

        int st = red[i].second.first, en = red[i].second.second;
        int dir1 = st - en;

        int from = red[k].second.first, to = red[k].second.second;
        int dir2 = from - to;

        if (red[i].first != red[k].first) continue;
        if (en < from or to < st) continue;
        if (dir1 * dir2 < 0) flag = false;
    }

    cout << (flag ? "Yes" : "No");

    return 0;
}