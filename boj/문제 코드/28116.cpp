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

    vector<int> arr(n), sorted(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;

        sorted[arr[i]] = i; 
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int dist = abs(sorted[i] - i);

        ans[i] += dist;
        ans[arr[i]] += dist; 
       
        arr[sorted[i]] = arr[i];
        sorted[arr[i]] = sorted[i];
    }

    for (auto& i : ans) {
        cout << i << ' ';
    }

    return 0;
}

/*
원본 배열

정렬 전의 위치를 가지고 있는 정렬된 배열



*/