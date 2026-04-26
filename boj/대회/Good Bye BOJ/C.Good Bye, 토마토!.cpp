#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d;
    cin >> n >> d;

    vector<iipair> A, arr;
    priority_queue<iipair> pq;

    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        arr.emplace_back(a,b);
        
        A.emplace_back(a, t);
        pq.emplace(b, t);
    }

    sort(A.begin(), A.end(), [](iipair& a, iipair&b){return a.second < b.second;});

    LL ans = 0;
    for (auto& [a, t] : A) {
        while (!pq.empty() && pq.top().second + t > d) {
            pq.pop();
        }

        if (!pq.empty()) {
            ans = max(ans, a + pq.top().first);
        }
    }

    for (auto& [a,b] : arr) {
        ans = max(ans, a + b);
    }

    cout << ans;

    return 0;
}

// D
// w 최댓값, e 최댓값
// Ai점 Bi점 Ti분
// 여러번 제출

/*
시간이 충분하다면 Ai가 큰거, Bi가 큰거 2개 제출하면 됨.

그렇지 않다면?
어쨌든 많아봐야 2개만 제출하면 됨.

음식을 차례로 선택

나머지 음식에서
시간 가능한 것들만 뽑고, 거기서 B가 가장 큰거 뽑기. X 뭘 A로 할지 모르잖아.

2포인터? ㄴㄴ

---
일단 2개 뽑을 수 있을 때만 보자.
1개만 줄 수 있다면, 그냥 고르면 되니깐.

(A, 시간) (B, 시간) 이렇게 나누고 

A는 맨 앞, B는 맨 뒤

A는 그냥 될 때마다 뒤로 한칸씩
B는 A와 B의 시간이 초과 될 때, 앞으로 한칸씩

지금 보는 B부터 앞까지의 최댓값을 알고 있어야 하는데, pq에 키는 값을 보는데 시간도 가지고 있다면?

*/