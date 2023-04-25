#include <iostream>
#include <vector>
#include <string>
#include "math.h"
using ll = long long;
using ld = long double;
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll inf=1e18;
 
    ll t;cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll ans=inf;
        for(char d='a';d<='z';++d) {
            // d is digit to preserve
            ll longestsequence = 0, currentseqlength=0;
            for(char c : s) {
                if (c!=d) {
                    ++currentseqlength;
                } else {
                    longestsequence=max(longestsequence, currentseqlength);
                    currentseqlength=0;
                }
            }
            longestsequence=max(longestsequence, currentseqlength);
            if (longestsequence==0) {
                ans=0;
            } else {
                ans=min<ll>(ans, 1+log2(longestsequence));
            }
        }
        cout<<ans<<'\n';
 
    }
    
    return 0;
}
