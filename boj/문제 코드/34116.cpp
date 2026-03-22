#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<iipair> arr(n);
    for (auto& [x, y] : arr) cin >> x >> y;

    LL res1 = 1e15, res2 = 1e15;
    LL btn = 1e15, ceiling = -1e15;
    LL leftUp = -1e15, rightDown = -1e15;
    
    for (int i = 0; i < n; i++) {
        btn = min(btn, arr[i].second);

        leftUp = max(leftUp, arr[i].second - arr[i].first);
        rightDown = max(rightDown, arr[i].second + arr[i].first);
    }

    res1 = leftUp - btn + rightDown - btn;

    leftUp = 1e15, rightDown = 1e15;

    for (int i = 0; i < n; i++) {
         ceiling = max(ceiling, arr[i].second);

         leftUp = min(leftUp, arr[i].second - arr[i].first);
         rightDown = min(rightDown, arr[i].second + arr[i].first);
     }

    res2 = -leftUp + ceiling -rightDown + ceiling;


    cout << min (res1, res2);
    return 0;
}


/*
이등변 삼각형이 만족하려면, 빗변을 수직으로 2등분 하는 선 위에 한 점이 있어야 함.
직각이 들어가려면 높이와, 빗변 절반 길이가 같아야 함

-> 빗변 하나 만들고, 그거 절반인 높이가 직각이등변 삼각형


가장 밑, 혹은 위에 있는 점을 기준으로 빗변을 그어야함.
대각선에 있으려면 y=x + a, y=-x + a 위에 있어야 함. 

기울기가 -일 때 최대 절편을 가지는 점, +일 때 최대 절편을 가지는 점이 삼각형의 그거 아니노.
가장 밑변 제외. 알아서 제외 되는 것 같기도.
*/