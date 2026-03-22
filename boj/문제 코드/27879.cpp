#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;


vector<int> operator+(const vector<int> & a, const vector<int> & b) {
    vector<int> ret = a;

    for (int i = 0; i < 4; i++) ret[i] += b[i];
    return ret;
}


vector<int> operator-(const vector<int>& a, const vector<int>& b) {
    vector<int> ret = a;

    for (int i = 0; i < 4; i++) ret[i] -= b[i];

    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;


    TwoVector<string> arr(n + 1, vector<string>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            cin >> arr[i][k];
        }
    }

    map<string, int> strToInt{{"aa", 0}, {"ab", 1}, {"ba", 2}, {"bb", 3}};

    TwoVector<vector<int>> prefixSumRow(n+1, vector<vector<int>>(n+1, vector<int>(4, 0)));
    TwoVector<vector<int>> prefixSumCol(n+1, vector<vector<int>>(n+1, vector<int>(4, 0)));

    for (int i = 2; i <= n; i++) {
        prefixSumRow[1][i] = prefixSumRow[1][i-1];
        prefixSumRow[1][i][strToInt[arr[1][i-1] + arr[1][i]]]++;

        prefixSumCol[i][1] = prefixSumCol[i-1][1];
        prefixSumCol[i][1][strToInt[arr[i-1][1] + arr[i][1]]]++;
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 2; k <= n; k++) {
            prefixSumRow[i][k] = prefixSumRow[i][k-1] + prefixSumRow[i-1][k] - prefixSumRow[i-1][k-1];
            prefixSumRow[i][k][strToInt[arr[i][k-1] + arr[i][k]]]++;


            prefixSumCol[i][k] = prefixSumCol[i][k - 1] + prefixSumCol[i - 1][k] - prefixSumCol[i - 1][k - 1];
            prefixSumCol[i][k][strToInt[arr[i-1][k] + arr[i][k]]]++;

        }
    }



    int qCnt;
    cin >> qCnt;
    while (qCnt--) {
        int i1, j1, i2, j2;
        string q;
        cin >> i1 >> j1 >> i2 >> j2 >> q;

        int qi = strToInt[q];

        int ret1 = (prefixSumRow[i2][j2] - prefixSumRow[i2][j1] - prefixSumRow[i1-1][j2] + prefixSumRow[i1-1][j1])[qi];
        int ret2 = (prefixSumCol[i2][j2] - prefixSumCol[i2][j1-1] - prefixSumCol[i1][j2] + prefixSumCol[i1][j1-1])[qi];

        cout << ret1 + ret2 << '\n';
    }

    return 0;
}

/*
길이가 2인 문자열의 개수만 구하면 된다. 문자는 2 종류고.

특정 문자열로 누적합하면 되는 거 아닌고?

연결이 끊겨야 하는 게, 연결되어 있어 그래도/ 그래서 더 많이 나와.
-> 이거 -1만 빼줬어도 그냥 됐을 것 같은데????? 아닌가봐 ㅋㅋ.

가로로 연결된거, 세로로 연결 된 거 따로 나눠야 할 것 같은데?

*/