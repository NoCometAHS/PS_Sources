#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int ans[20];

int func(LL num) {
    if (!num) return 1;

    bool minus = num < 0;
    if (minus) num = -num;

    int size = 1;
    LL gop = 1, sum = 1;
    while (sum < num) gop*=3, size++, sum += gop;

    ans[size] = 1;
    func(num - gop);

    if (minus) {
        for (int i = size; i >= 1; i--) ans[i] = -ans[i];
    }
    
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;

    
    int st = func(n);
    for (int i = st; i >= 1; i--) {
        if (ans[i] < 0) cout << "T";
        else cout << ans[i];
    }

    return 0;
}

/*
가장 큰 3의 제곱수 놔두고 만들죠.
*/