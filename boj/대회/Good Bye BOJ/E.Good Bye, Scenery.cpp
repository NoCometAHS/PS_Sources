#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;
int segSz = 300300 * 4;
LL frontSegTree[300300*4];

void init() {
    fill(frontSegTree, frontSegTree + segSz, 0);
}

void add(int idx, int v, int node = 1, int lt = 0, int rt = 300000) {
    if (lt == rt) {
        frontSegTree[node]+= v;
        return;
    }

    int mid = (lt + rt) / 2;
    if (idx <= mid) {
        add(idx, v, node*2, lt, mid);
    }
    else {
        add(idx, v, node*2+1, mid+1, rt);
    }

    frontSegTree[node] = frontSegTree[node*2] + frontSegTree[node*2+1];
    return;
}

LL sum(int bg, int end, int node = 1, int lt = 0, int rt = 300000) {
    if (bg <= lt && rt <= end) return frontSegTree[node];
    if (rt < bg || end < lt) return 0;

    int mid = (lt + rt) /2;
    LL ret = 0;
    ret += sum(bg, end, node*2, lt, mid);
    ret += sum(bg, end, node*2+1, mid+1, rt);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        segSz = n*4;
        
        vector<int> cnt(300300, 0), arr(n);
        for (auto& i : arr) {
            cin >> i;
            cnt[i]++;
        }

        bool f = false;
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i-1];
            
            if (cnt[i] > i) f = true;
        }


        if (f) {
            cout << -1 << '\n';
            continue;
        }


        init();
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            LL d = cnt[arr[i]-1] - sum(0, arr[i]-1);

            if (i + d >= arr[i]) {
                ans += i+d - arr[i] + 1;
            }

            add(arr[i], 1);
        }


        cout << ans << '\n';
    }



    return 0;
}

// 한줄로 n개
// n명의 사진가, i번째 사진가는 1~Ai번째의 곳에서 사진찍고 싶음
// 인접한 두 사진가 위치 바꾸기.
/*

각 놈들을 stable sort한 다음에, 번호를 다시 매겨.
그러면 그 번호가, 그 사람의 가야할 위치.
라고 하면, 332인 경우가 반례

불가능한 경우는
일단 Ai를 배열에다 넣고, prefixsum을 구해.
이 값이 인덱스를 넘는다면 불가능.

된다고 한다면,

냅둬도 되는 얘들이랑 옯겨야 하는 얘들을 식별할 수 있나?

332같은 경우에
132로 바꿔주는 것처럼.


카운팅 소트 해놨으니깐
비는만큼 뒤에 숫자를 바꿔주기?

이미 숫자가 존재하다면 ㅇㅇ.

최대한 같은 숫자를 늘리는게 목적

앞에 있는 얘를 바꿔주는게 좋겠지? 씁, 그러다가 잘못해서 뒤에거 작은 숫자로 바꾸는 것도 별론데.


카운팅 배열가지고 할 수는 없을까?
어떤 수 a가 i번째에 있을때,

앞에 뭐가 있는지는 신경 안써도 돼. 여기거 어떻게 하든간에 난 앞으로 가게 되니깐.
주의할 건 뒤에 있는 애들, 얘들이 내 앞으로 오면 난 뒤로 가버려.


cnt[i] = k
i번째 안으로 들어가야하는 숫자가 k개
만약 i+k가 a보다 작으면 넘겨.
흠


nxt = i + (내 앞으로 가야하는 숫자 개수 - 내 뒤로가야하는 숫자 개수)
nxt <= a : 가만히 있기
nxt > a : nxt - a 만큼 앞으로 가기


내 앞으로 가야하는 숫자 개수 = ?
내 뒤로 가야하는 숫자 개수는 = ?

세그트리쓰면 좀 쉽게 되긴 할듯?

흠흐므흐ㅡ 이게 아닌 것 같은데



*/