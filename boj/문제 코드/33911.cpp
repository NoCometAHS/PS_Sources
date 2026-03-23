#include "bits/stdc++.h"

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cnt(101, 0);
    set<int> d;
    priority_queue<int> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
    }

    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == 1) pq.push(i);
        else if (cnt[i] >= 2) d.insert(i);
    }
    
    vector<int> big;
    while (!pq.empty() && big.size() < 3) {
        big.push_back(pq.top());
        pq.pop();
    }

    while(big.size() < 3) big.push_back(0);

    int ans = 0;
    for (int a = 1; a <= 98; a++) {
        for (int b = a+1; b <= 99; b++) {
            for (int c = b+1; c <= 100; c++) {
                bool f = false;
                vector<int> cur{c,b,a};
                
                for (int i = 0, j = 0; i < 3 && j < 3; i++, j++) {
                    if (cur[i] == big[j]) continue;
                    if (d.count(cur[i])) {
                        j--;
                        continue;
                    }

                    if (cur[i] > big[j]) {
                        f = true;
                        break;
                    }
                    else {
                        break;
                    }
                }

                ans += f;
            }
        }
    }

    cout << ans;


    return 0;
}

/*
1. 이미 2번씩 선택된 수는 거른다.
2. 1번만 선택된 수보다 큰 수를 고른다
    2-1. 1번만 선택된 수보다 큰 수가 없다? 그 수를 고르고 1번으로.

이제 무조건 골라야 하는 수들이 정해졌다.
나머지 숫자는 아무거나 고르기.

아니 이거 근데 브포아님?

1번씩 선택된 것중, 큰거 3개 가지고 있고, 2번씩 선택된것만 가지고 있음 될 듯.
*/