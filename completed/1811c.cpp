#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n; cin>>n;
        ll a[n], b[n-1];
        cin>>b[0];
        a[0]=b[0];
        for (ll i=1;i<n-1;++i) {
            cin>>b[i];
            a[i]=min(b[i-1], b[i]);
        }
        if(n>2 && b[n-2]>b[n-3]) {
            a[n-1]=b[n-2];
        }
        else {
            a[n-1]=0;
        }
        for(ll i : a) cout << i << ' ';
        cout<<'\n';
	}
    
    return 0;
}
