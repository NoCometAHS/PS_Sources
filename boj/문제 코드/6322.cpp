#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed;
    cout.precision(3);

    int i = 1;
    while (a) {


        cout << "Triangle #" << i++ << '\n'; 
        if (a == -1) {
            a = c*c - b*b;

            if (a <= 0) {
                cout << "Impossible.";            
            }
            else cout << "a = " << sqrt(a); 
        }
        else if (b == -1) {
            b = c*c - a*a;

            if (b <= 0) {
                cout << "Impossible.";            
            }
            else cout << "b = " << sqrt(b); 
        }
        else {
            cout << "c = " << sqrt(a*a + b*b); 
        }

        cout << "\n\n";
        cin >> a >> b >> c;
    }
    return 0;
}
