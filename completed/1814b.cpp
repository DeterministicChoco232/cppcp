#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll a,b; cin>>a>>b;
        ll x=sqrt(a+b)-100;
        ll minMoves = 1e15;
        for(int i=0;i<=200;++i) {
            ++x;
            if(x<1) continue;
            minMoves=min<ll>(minMoves, x-1+ceil(double(a)/x)+ceil(double(b)/x));
        }
        cout<<minMoves<<'\n';
	}
    
    return 0;
}
