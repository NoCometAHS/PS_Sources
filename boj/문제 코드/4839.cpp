#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

vector<LL> sieve(10000, false);
vector<LL> primes;

void InitPrimes() {
    for (LL i = 2; i < 10000; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);

        for (LL k = i * i; k < 10000; k += i) {
            sieve[k] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    InitPrimes();


    LL n;
    cin >> n;
    while (n) {
        LL a = n;


        LL d = 2;
        auto it = primes.begin();

        while (n / d > *it){
            it++;
            d *= *it;
        }

        vector<LL> coef, x;

        while (n) {
            if (n >= d) {
                coef.push_back(n / d);
                x.push_back(d);

                n -= n / d * d;
            }

            d /= *it;

            it--;
        }


        cout << a << " = ";
        string sx;

        LL cur = 1;
        auto i  = primes.begin();

        while (!coef.empty()) {
            cout << coef.back();
            coef.pop_back();

            while (x.back() != cur) {
                sx += "*" + to_string(*i);
                cur *= *i;
                i++;
            }

            x.pop_back();

            cout << sx;
            
            if (coef.size() != 0) {
                cout << " + ";
            }
        }
        cout << '\n';
        cin >> n;
    }
    return 0;
}

