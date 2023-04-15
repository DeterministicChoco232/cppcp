#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	ll t;
	cin >> t;
    while(t--) {
        ll n;cin>>n;
        ll a[n],b[n];
        for(ll i=0;i<n;++i) {
            cin>>a[i];
            cin>>b[i];
        }
        ll ans=1;
        ll gcd=a[0]*b[0];
        ll lcm=1;
        for(ll i=0;i<n;++i) {
            lcm*=b[i]/__gcd(lcm,b[i]);
            gcd=__gcd(gcd, a[i]*b[i]);
            if (gcd%lcm!=0) {
                lcm=b[i];
                gcd=a[i]*b[i];
                ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
