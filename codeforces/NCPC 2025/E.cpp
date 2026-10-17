#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

ll n, tot_c;

string word[303];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(ll i=0; i<n; i++){
        cin>>word[i];
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n*2-1; j++){
            if(word[i][j]=='C'){
                tot_c++;
            }
        }
    }
    
    return 0;
}