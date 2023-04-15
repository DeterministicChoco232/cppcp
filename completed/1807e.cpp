#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

	ll t;
	cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll a=0;
        ll c[n+1];c[0]=0;
        for(ll i=1;i<=n;++i) {
            cin>>a;
            c[i]=c[i-1]+a;
        }
        ll low=1,high=n;
        while (high > low) {
            ll mid = (low+high) / 2;
            cout << "? " << mid-low+1;
            for (ll i=low;i<=mid;++i)
                cout<<' '<<i;
            cout<<endl;
            ll resp;cin>>resp;
            if (resp!=c[mid]-c[low-1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << "! " << low << endl;
    }
    return 0;
}
