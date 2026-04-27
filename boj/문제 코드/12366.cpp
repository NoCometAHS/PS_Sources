#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    int t = 1;
    while (tc--) {
        int n;
        cin >> n;

        vector<iipair> arr(n);
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
        }

        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;

            arr[i].first = p;
            arr[i].second = i;
        }

        stable_sort(arr.begin(), arr.end(), [](const iipair& a, const iipair& b) {return a.first > b.first;});


        cout << "Case #" << t++ << ": ";
        for (auto& [i, k] : arr) cout << k << ' ';
        cout << '\n';
    }
    return 0;
}

// 아마 기대값?
// ㄴㄴ 일다 l이 전부 1이면 확률만 보면 돼.
/*
    마지막까지 가서 반복하는 것보단, 처음 여러번 반복해서 뚫는게 시간 절약이 되니깐 걍 내림차순 정렬하면 될 듯.
*/