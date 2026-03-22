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
    
    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = 0;
    while (arr.size() > 1) {
        int a = arr.back();
        arr.pop_back();
        int b = arr.back();
        arr.pop_back();

        ans += a * b;
        arr.push_back(a + b);
    }

    cout << ans;
    return 0;
}

/*
기본적인 생각으론
큰것부터 차례대로 합치면 될 것 같은데,

a : 1 2 3 4

1.
p : 12
a : 1 2 7

p : 26
a : 1 9

p : 35
a : 10

2.
p : 4
a : 2 3 5

p : 10
a : 5 5

p : 35
a : 10

a : 1 2 3 인 경우에선 2의 경우가 안 되고.

큰 수를 먼저 해야, 점수에 어떤 숫자와 곱으로 자주 들어가니깐 큰 수 부터 해야 할 것 같은데.
\
??? 
순서 상관 없다고?
1 2 3 은 아닌 거 아녔어?

p : 2
a : 3 3

p : 11
a : 6

ㄹㅇ이네 계산을 못 했었네 ㅋㅋㅋㅋㅋ.
*/