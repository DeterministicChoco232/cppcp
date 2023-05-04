#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll inf=1e18;

    ll n,q;
    cin>>n>>q;
    bool red=false;
    ll a[n], b[n], slen=1;
    cin>>a[0];
    b[0]=1;
    for(ll i=1;i<n;++i) {
        cin>>a[i];
        if(red && a[i]<=a[i-1]) {
            --slen;
        }
        ++slen;
        b[i]=slen;
        red=a[i]<=a[i-1];
    }
    for(ll j=0;j<q;++j) {
        ll l,r;
        cin>>l>>r;
        ll ans=b[r-1];
        if(l>1)ans-=b[l-2];
        if(l>1) {
            if(a[l]<=a[l-1]&&a[l-1]<=a[l-2]) ++ans;
        }
        if(l>2) {
            if(a[l-1]<=a[l-2]&&a[l-2]<=a[l-3]) ++ans;
        }
        if(r-l<=1) ans=r-l+1;
        cout<<ans<<endl;
    }
    
    return 0;
}
