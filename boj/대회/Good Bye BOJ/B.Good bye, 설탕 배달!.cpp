#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

struct ability{
    LL a;
    LL b;
    LL c;
    LL day;
    LL cnt;
    ability(LL& a, LL& b, LL& c, LL& d) : a(a), b(b), c(c), day(d), cnt(1) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<ability> arr;

        while (n--) {
            LL a, b, c, d;
            cin >> a >> b >> c >> d;

            if (!arr.empty() && arr.back().day == d) {
                ability& cur = arr.back();

                cur.a = max(cur.a, a);
                cur.b = max(cur.b, b);
                cur.c = max(cur.c, c);
                cur.cnt++;
            }
            else {
                arr.emplace_back(a,b,c,d);
            }
        }

        bool ans = true;
        LL cur = 1;
        LL ca = 0,cb = 0,cc = 0;
        for (auto& [a,b,c, day, cnt] : arr) {
            LL sum = 0;
            sum = (a - ca < 0 ? 0 : a - ca) + (b - cb < 0 ? 0 : b - cb) + (c - cc < 0 ? 0 : c - cc);

            if (day - cur + 1 - cnt >= sum) {
                cur += sum+cnt;
                ca = max(ca, a);
                cb = max(cb, b);
                cc = max(cc, c);
            }
            else {
                ans = false;
                break;
            }

            cout << ca << ' ' << cb << ' ' << cc << ' ' << cur << '\n';
        }


        cout << (ans ? "YES\n" : "NO\n");
        cout << '\n';
    }

    return 0;
}

// i 는 ai bi ci 만큼 더 필요
// 하루당 3중 하나 1 올림
// pi일까지는 풀어.
// 뒷쪽으로 갈 수록 여유

/*
각 일차당 가장 큰 놈들만 모아둬 각 요소별로
그럼 얼마만큼씩 필요한 지 알 수 이썽.

2 1 0 5
3 3 1 10
3 3 2 12
3 5 3
*/