#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

tuple<int, int, string> dfs(vector<iipair>& contiZeros, string& str, int m, int depth) {
    if (depth == contiZeros.size()) {
        int mxLen = 0, curLen = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') {
                curLen = 0;
            }
            else {
                curLen++;
                mxLen = max(mxLen, curLen);
            }
        }

        return {mxLen, m, str};
    }


    auto res = dfs(contiZeros, str, m, depth+1);

    if (contiZeros[depth].second <= m) {
        for (int i = contiZeros[depth].first, k = 0; k < contiZeros[depth].second; i++, k++) {
            str[i] = '1';
        }

        res = max(res, dfs(contiZeros, str, m - contiZeros[depth].second, depth+1));

        for (int i = contiZeros[depth].first, k = 0; k < contiZeros[depth].second; i++, k++) {
            str[i] = '0';
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL n, m;
        cin >> n >> m;

        string str(bitset<32>(n).to_string());
        
        int firstOneIndex = -1;
        while (str[++firstOneIndex] == '0');

        vector<iipair> contiZeros;
        for (int i = firstOneIndex; i < str.length(); i++) {
            if (str[i] == '1') {
                while (str[++i] == '1');
                contiZeros.push_back({i, 1});
            }
            else contiZeros.back().second++;
        }

        auto [mxLen, leftM, ss] = dfs(contiZeros, str, m - 1, 0);
        m = leftM + 1;
        str = ss;

        vector<int> contiOnes;
        int len = 0;
        firstOneIndex = -1;
        while (str[++firstOneIndex] == '0');

        for (int i = firstOneIndex; i < str.length(); i++) {
            if (str[i] == '0') {
                contiOnes.push_back(len);
                len = 0;
            }
            else len++;
        }   
        contiOnes.push_back(len);

        sort(contiOnes.begin(), contiOnes.end());

        int ans = 0;
        while (!contiOnes.empty() && m > 0) {
            ans += contiOnes.back();
            contiOnes.pop_back();

            m--;
        }

        cout << ans + m << '\n';

    }
    return 0;
}


/*
음이 아닌 정수 n

k번의 움직임.
움직임은 다음을 의미한다. 음이 아닌 정수 l을 하나 고르고, n = n + 2^l

한 움직임의 점수는 
현재 수에 2^l을 2진수로 더할 때 생기는 2진수 올림의 개수.

최대 점수는?

---
안전 LL

k가 10억이네??

한 번의 움직임에서 많은 점수를 벌려면?
-> 연속한 1이 있는 곳의 시작에 1을 더해야해

그렇게 많은 올림을 진행하면 하나의 1로 변해버려.
-> 종국에는 1하나만 남아서 k가 아무리 커도 상관이 없어

1001
1011
1111
10000
4점

1001
1010
1100
10000
4점

중간을 채우 듯이 하든
작은거 끌어올리 듯이 하든 상관 X

연결하는 게 의미 없으면
2개 이상의 연결된 얘들만 1씩 더해주고
나머지는 그냥 이미 1인 곳에 계속 더해만 주면 되나?

11001
11011
11111
100000
5점

11001
100001
100010
100100
4점

연결해서 터트려야 함. 긴거 먼저 터트리면 안 됨.


k가 크다면 모든 1사이의 공간 채우고 터트린다음 1에다가 계속 더하면 됨.

k가 작다면
최대한 가장 길게 1을 연결시키고 남은 것들은 그나마 연속한 얘들에 터트리거나 1 하나에 터트리기.


어떻게 연결해야 최대한 가장 길게 1을 연결할 수 있을까?

n은 2의 30승

비어있는 곳이 많아 봐야 15개

2^15는? 브포 때리자.

*/