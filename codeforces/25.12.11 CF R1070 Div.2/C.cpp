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

        vector<LL> even, odd;
        for (int i = 0; i < n; i++) {
            LL num;
            cin >> num;
            if (num % 2) odd.push_back(num);
            else even.push_back(num);
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        if (even.size() == n) {
            for (int i = 0; i < n; i++) {
                cout << "0 ";
            }
            cout << '\n';
        }
        else if (odd.size() == n) {
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    cout << "0 ";
                }
                else cout << odd.back() << " ";
            }
            cout << '\n';
        }
        else if (odd.size() == 1) {
            LL sum = odd.back();
            cout << sum << ' ';
            for (int i = 1; i < n; i++) {
                sum += even.back();
                even.pop_back();

                cout << sum << ' ';
            }
            cout << '\n';
        }
        else {
            LL sum = odd.back();

            cout << sum << ' ';
            for (int i = even.size()-1; i >= 0; i--) {
                sum += even[i];
                cout << sum << ' ';
            }

            for (int i = 1; i < even.size(); i++) even[i] = even[i-1];

            for (int i = 2; i <= odd.size(); i++) {
                if (i % 2) {
                    cout << sum << ' ';

                }
                else {
                    if (i == odd.size()) cout << "0 ";
                    else cout << sum - (i - 1 >= even.size() ? even.back() : even[i-1]) << ' ';
                }
            }

            cout << '\n';
        }
        
    }
    return 0;
}

/*
숫자가 적혀 있는 n개의 코인, 자연수 k

코인 넣을 수 있는 빈 가방.

정확히 k번 행동
코인 하나 가져가기.

짝수 좋아하는 고양이. 가방 안의 코인 숫자 합이 짝수가 될 때마다 가방이 비워짐

숫자의 합이 점수.
마지막 숫자 합이 최대가 되도록하는 행동.

1~n의 모든 경우에 k에 대한 답을 찾으셈.


---
** 문제의 키가 문제에서 나온 부분이 아니라 내가 알고 있는 것이 될 수가 있네?!! 밑에 짝홀 써둔게 도움이 많이 됐어. + 가정하는 것도.**

짝짝 = 짝
짝홀 = 홀
홀홀 = 짝

점수가 가장 커지게 되는 경우는?
- 홀수를 1개만 두고 계속 짝수만 더하는 경우.

어떤 경우에 답이 작아질까.
1. 짝수만 있거나
2. 홀수가 2개 이상 있거나.
3. 홀수만 있다. 


경우를 나눠서 하자.
1. 짝수만 있다.
무조건 0.

2. 홀수만 있다.
k가 짝수일때 무조건 0, 홀수이면 가장 큰 홀수가 답.

3. 홀수가 1개만 있다.
k=1 -> 홀수
k>1 -> 홀수에 큰 순서대로 짝수르 더함.

4. 홀수가 2개 이상.
k-1 <= 짝수 개수 
가장 큰 홀수와 큰 순서대로 짝수로 채움.

k-1 > 짝수 개수
p = k - 짝수 개수.

p가 짝수
작은 홀수 2개
큰 홀수, 짝수 큰 순서대로.


p가 홀수
가장 큰 홀수 + 모든 짝수의 합
*/