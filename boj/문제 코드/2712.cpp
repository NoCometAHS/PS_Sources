#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;


    cout << fixed;
    cout.precision(4);

    while (tc--) {
        double v;
        string u;
        cin >> v >> u;

        if (u == "kg") {
            cout << v * 2.2046 << " lb\n";
        }  
        else if (u == "lb") {
            cout << v * 0.4536 << " kg\n";
        }
        else if (u == "l") {
            cout << v * 0.2642 << " g\n";
        }
        else {
            cout << v * 3.7854 << " l\n";
        }
    }
    
    return 0;
}