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

    while (tc--) {
        int n;
        cin >> n;

        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            pq.push(t);
        }


        vector<int> ans;
        priority_queue<int> nxtPq;
        while (!pq.empty()) {
            int mx = pq.top(), cnt = 0;
            while (!pq.empty() and pq.top() == mx) {
                ans.push_back(mx);
                pq.pop();
                cnt++;
            }

            
            while (!pq.empty()) {
                int cur = pq.top(), curCnt = 0;

                while (!pq.empty() and pq.top() == cur and curCnt < cnt) {
                    ans.push_back(pq.top());
                    pq.pop();
                    curCnt++;
                }

                while (!pq.empty() and pq.top() == cur) {
                    nxtPq.push(pq.top());
                    pq.pop();
                }
            }

            swap(pq, nxtPq);
        }

        for (auto& i : ans) {
            cout << i << ' ';
        }
        cout << '\n';

    }
    

    return 0;
}

/*
mode of array는 빈도 높은 숫자. 같다면 그 중 큰거.

배열 순서 바꿔도 됨.
모든 prefix의 mode 합을 최대화.

가장 큰 숫자 먼저.
전부 넣어버려.
그리고 작은 숫자들 그 개수 이하번 넣어.
그다음 큰 숫자 추가하고 반복.

*/