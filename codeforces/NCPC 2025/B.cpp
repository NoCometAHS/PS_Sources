#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

struct book {
    int num;
    int height;
    int thickness;

    book(int n = -1, int h = -1, int t = -1) : num(n), height(h), thickness(t) {}

    bool operator<(const book& a) {
        return height < a.height;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h, w;
    cin >> n >> h >> w;

    vector<book> arr(n);
    int tt = 0;
    for (auto& [num, hight, thick] : arr) {
        num = ++tt;
        cin >> hight >> thick;
    }

    sort(arr.begin(), arr.end());

    vector<int> stacked, upright;
    int stackedHeight = 0;

    while (arr.back().height > h) {
        stacked.push_back(arr.back().num);
        stackedHeight += arr.back().thickness;

        arr.pop_back();
    }

    vector<int> dp(350, -1);

    int leftHeight = h - stackedHeight; 
    dp[0] = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int lh = leftHeight;  lh >= arr[i].thickness; lh--) {
            if (dp[lh - arr[i].thickness] == -1) continue;

            dp[lh] = i;
        }
    }

    int most = 0;
    for (int i = leftHeight; i >= 0; i--) {
        if (dp[i] == -1) continue;
        most = i;
        break;
    }


    unordered_set<int> chk;
    for (int thick = most; thick; thick -= arr[dp[thick]].thickness) {
        stacked.push_back(arr[dp[thick]].num);
        chk.insert(arr[dp[thick]].num);
    }

    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (chk.count(arr[i].num)) continue;
        
        sum += arr[i].thickness;
        if (sum < w) break;

        upright.push_back(arr[i].num);
    }


    if (stacked.size() + upright.size() == n) {
        cout << "upright ";
        for (auto& i : upright) cout << i << ' ';
        cout << '\n';

        cout << "stacked ";
        for (auto& i : stacked) cout << i << ' ';
    }
    else {
        cout << "impossible";
    }



    return 0;
}
