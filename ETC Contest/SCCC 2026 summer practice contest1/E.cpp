#include "bits/stdc++.h"

using namespace std;
using LL = unsigned long long;



int main() {
    LL N, K;
    cin >> N >> K;

    LL n1 = __builtin_popcountll(N);
    bitset<64> N2bit(N);
    
    if (n1 < K) {
        int needed = K - n1;
        for (int i = 0; needed; i++) {
            if (N2bit[i] == 1) continue;
            N2bit[i] = 1;
            needed--;
        }

        N = N2bit.to_ullong();
    }
    else if (n1 == K) {
        vector<int> tmp;
        for (int i = 0; i < 64; i++) {
            tmp.push_back(N2bit[63-i]);
        }

        next_permutation(tmp.begin(), tmp.end());
        
        for (int i = 0; i < 64; i++) {
            N2bit[i] = tmp[63 - i];
        }

        N = N2bit.to_ullong();
    }
    else {
        int needed = n1 - K;
        for (int i = 0; needed; i++) {
            if (N2bit[i] == 1) {
                N2bit[i] = 0;
                needed--;
            }
        }

        vector<int> tmp;
        while (N2bit.to_ullong() <= N) {
            for (int i = 0; i < 64; i++) {
                tmp.push_back(N2bit[63-i]);
            }

            next_permutation(tmp.begin(), tmp.end());
            
            for (int i = 0; i < 64; i++) {
                N2bit[i] = tmp[63 - i];
            }
        }

        N = N2bit.to_ullong();
    }

    cout << N;

    return 0;
}