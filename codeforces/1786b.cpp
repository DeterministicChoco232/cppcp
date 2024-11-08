#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n,w,h; cin>>n>>w>>h;
        ll a[n];
        ll freedom=(w-h)*2;
        for(ll i=0;i<n;++i) cin>>a[i];
        ll diffMin=2e9, diffMax=-2e9;
        for(ll i=0;i<n;++i) {
            ll b; cin>>b;
            diffMin=min(diffMin, a[i]-b);
            diffMax=max(diffMax, a[i]-b);
        }
        cout<<((abs(diffMax-diffMin)<=freedom)?"Yes\n":"No\n");
    }
    
    return 0;
}
