#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;
	cin >> t;
    while (t--) {
        ll n,q;
        cin>>n>>q;
        ll a[n+1];
        a[0]=0;
        for(int i=1;i<=n;++i) {
            int temp; cin >> temp;
            a[i]=(a[i-1]+temp)%2;
        }
        while(q--) {
            ll l,r,k;
            cin>>l>>r>>k;
            if((a[r]-a[l-1]+k*(r-l+1)+a[n])%2==1) {
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
    }
    
    return 0;
}
