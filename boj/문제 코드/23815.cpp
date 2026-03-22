#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int cal(int a, char op, int b) {
    if (a <= 0) return -1e9;
    switch(op) {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '/':
        return a / b;

    case '*':
        return a * b;
    }

    return -1;
}

int ff(int a) {
    if (a <= 0) return -1e9;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int dp[2][2][100100] = {0,};
    dp[1][1][0] = dp[1][0][0] = dp[0][1][0] = dp[0][0][0] = 1;

    bool f = true;

    for (int i = 1; i <= n; i++) {
        char op1, op2;
        int num1, num2;
        cin >> op1 >> num1 >> op2 >> num2;

        dp[0][0][i] = max(cal(dp[0][0][i-1],op1, num1), cal(dp[0][1][i-1], op1, num1));
        dp[0][1][i] = max(cal(dp[0][0][i-1],op2, num2), cal(dp[0][1][i-1], op2, num2));
        dp[1][0][i] = max({ff(dp[0][0][i-1]), ff(dp[0][1][i-1]), cal(dp[1][0][i-1], op1, num1), cal(dp[1][1][i-1], op1, num1)});
        dp[1][1][i] = max({ff(dp[0][0][i-1]), ff(dp[0][1][i-1]), cal(dp[1][0][i-1], op2, num2), cal(dp[1][1][i-1], op2, num2)});

        
        if (dp[0][0][i] <= 0 && dp[0][1][i] <= 0 && dp[1][0][i] <= 0 && dp[1][1][i] <= 0) {
            f = false;
            break;
        }
    }

    if (f) {
        cout << max({dp[0][0][n], dp[0][1][n], dp[1][0][n], dp[1][1][n]});
    }
    else {
        cout << "ddong game";
    }
    return 0;
}

/*

dp[광고를 봤는지][선택지][n]


dp[광고를 봤는지 아닌지][n]

dp[0][n] = max(dp[0][n-1] op1 N1, dp[0][n-1] op2 N2)
dp[1][n] = max(dp[0][n-1], dp[0][n-1], dp[1][n-1] ..)

아;;
되네;;
*/
