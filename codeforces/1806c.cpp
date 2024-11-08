#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll inf=1e17;

	ll t;cin >> t;
	while(t--) {
        ll n;
        cin>>n;
        ll p[2*n], difffromnull=0;
        for(ll i=0;i<2*n;++i) {
            cin>>p[i];
            difffromnull+=abs(p[i]);
        }
        ll ans=difffromnull;
        if(n==1) ans=abs(p[1]-p[0]);
        if(n==2) {
            ll difftwovec=0;
            for(ll i=0;i<4;++i)
                difftwovec+=abs(p[i]-2);
            ans=min(ans, difftwovec);
        }
        if(n%2==0) {
            ll highest=-inf, diffnegonevec=0;
            for(ll i=0;i<2*n;++i) {
                diffnegonevec+=abs(p[i]+1);
                if(p[i]>highest)highest=p[i];
            }
            ans=min(ans, diffnegonevec-abs(highest+1)+abs(highest-n));
        }
        cout<<ans<<'\n';
	}
    
    return 0;
}
