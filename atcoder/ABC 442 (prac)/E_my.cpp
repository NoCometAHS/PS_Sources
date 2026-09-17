/*
 정리하면, 각 몬스터를 위치를 방향 벡터로 생각하고, 일단 기약분수로 만들어. 그럼 일직선에 있는 얘들은 다 합쳐질거야.
 그런 방향 벡터를 ccw 기준 정렬 -> 이거 뭔가 좀 이상한 것 같기도 하고. 그냥 ccw 만 넣어서 정렬이 되나?
 그리고 누적합 한다음에 쿼리 받으면 처리.


*/


#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

LL _gcd(LL a, LL b) {
    if (a % b) return gcd(b, a % b);
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    vector<iipair> arr(n);
    map<iipair, int> cnt;
    vector<iipair> leans;
    for (auto& [x, y] : arr) {
        cin >> x >> y;

        LL gcd = _gcd(abs(x), abs(y));
        x /= gcd, y /= gcd;

        if (cnt.count(x, y) == 0) leans.emplace_back(x, y);
        cnt[{x, y}]++;
    }

    sort(leans.begin(), leans.end(), [&](const iipair& a, const iipair& b) {
        auto ccw(iipair a, iipair b, iipair c) {
            return a.first*b.second + b.first*c.second + c.first*a.second - (a.second * b.first + b.second * c.first + c.second * a.first);
        }

        return ccw(a, {0, 0}, b) > 0;
    }
    );


    vector<int> leanIdx;
    for (auto& [x, y] : arr) {
        
    }


    return 0;
}

/*
기준을 내 마음대로 잡을 수 있으면 **시계방향 정렬**이 가능할텐데.
아닌가? 그냥 가능한가?

각도를 키로 하는 map?
각도를 기울기를 나타내는 pair로 둬. (기약분수로)
-> 몇 분면인지는 어떻게 구분하지 -> 벡터? -> 분자 분모의 음수 양수로 구분 될듯.

그럼 정렬은? (1, 0)을 기준으로 ccw?

그리고 {몬스터: 각도에 해당하는 인덱스}를 하는 map도 하나 나둬.
*/