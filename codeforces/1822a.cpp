#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll inf=1e18;

	ll t;cin >> t;
	while(t--) {
        ll n, t;
        cin >> n >> t;
        ll a[n], b[n];
        for(ll i=0;i<n;++i)
            cin>>a[i];
        for(ll i=0;i<n;++i)
            cin>>b[i];
        ll index=-2, interest=-1;
        for(ll i=0;i<n;++i) {
            if(i+a[i] <= t) {
                if(b[i] > interest) {
                    interest=b[i];
                    index=i;
                }
            }
        }
        cout<<index+1<<'\n';
	}
    
    return 0;
}
