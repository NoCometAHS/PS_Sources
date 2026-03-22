#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL h, n, q;
    cin >> h >> n >> q;

    vector<LL> arr(n);
    priority_queue<LL, vector<LL>, greater<LL>> pq;

    for (auto& i : arr) cin >> i;
    sort(arr.begin(), arr.end());

    LL sum = 0;
    while (h > sum && !arr.empty()) {
        LL c = arr.back();
        arr.pop_back();

        sum += c;
        pq.push(c);
    }

    cout << (LL)(sum < h ? -1 : pq.size()) << '\n';

    while (q--) {
        LL x;
        cin >> x;

        sum += x;
        pq.push(x);

        if (sum < h) {
            cout << -1 << '\n';
        }
        else {
            while (sum - pq.top() >= h) {
                sum -= pq.top();
                pq.pop();
            }

            cout << pq.size() << '\n';
        }
    }

    return 0;
}

/*
최소값 pq로 써야 하는 카드들 저장하고
만약 공격력이 넘치면 빼가면 되겠다.
*/