#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<bitset<30>> arr(m);
    for (int i = 0; i < n-1; i++) {
        int c;
        cin >> c;

        while (c--) {
            int num;
            cin >> num;
            num--;

            arr[num].set(i);
        }
    }


    unordered_map<int,int> cnt;
    for (auto& i : arr) {
        LL a = i.to_ulong();
        cnt[a]++;
    }

    if (cnt.count(0) && cnt[0] >= 2) {
        cout << 0;
        return 0;
    }

    LL ans = 1;
    for (auto& [a, c] : cnt) {
        if (a == 0) continue;
        
        if (c >= 3) {
            ans = 0;
            break;
        }

        ans *= 2;
    }
    cout << ans;

    return 0;
}

/*
모든 과목의 조합을 구하는 건 ㅂㄱㄴ

같이 S[n]을 등록 할 수 있느냐.

만약 듣고 있는 과목이 같은 친구가 있다면,
그 사람들을 나눠줄 수 있을만한 과목이 있으면 된다.

없으면 1명이라고 생각하고 계산해야지.

서로 구분 될 수 있는 사람들만 구해서 조합 공식 사용하면 될 듯.
ㅈㅁㅈㅁㅈㅁ, 다른 과목을 더 추가하는 게 아니라, 그냥 거기서 생각하는 거 아니냐.

같으면 그 같은 수만큼 곱해줘야 할 것 같은데.

같은 사람 중이 3 이상이면 0을 출력해야 하나
*/