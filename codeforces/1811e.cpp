#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

ll checkDifference(ll a, ll k) {
    ll temp1=a;
    for(ll i=0; i<=12; ++i) {
        ll temp2=a/pow(10,i);
        if(temp2==0) break;
        temp1-=pow(9,i)*(temp2/10+(temp2%10>=4));
    }
    return k-temp1;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll k; cin>>k;
        ll a=k;
        ll increment=checkDifference(a, k);
        while(increment!=0) {
            a+=increment;
            increment=checkDifference(a, k);
        }
        cout<<a<<'\n';
	}
    
    return 0;
}
