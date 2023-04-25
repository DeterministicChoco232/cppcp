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
        ll n;
        cin>>n;
        ll a[n];
        for (ll i=0;i<n;++i)
            cin>>a[i];
        ll maxPos=0, minNeg=0;
        ll maxBeauty=0;
        for (ll i=0;i<n;++i) {
            if (a[i]>0) {
                maxBeauty = max(maxBeauty, maxPos*a[i]);
                maxPos=max(maxPos, a[i]);
            } else {
                maxBeauty = max(maxBeauty, minNeg*a[i]);
                minNeg=min(minNeg, a[i]);
            }
        }
        if (n==2 && a[0]*a[1]<maxBeauty) maxBeauty=a[0]*a[1];
        cout << maxBeauty<<'\n';
	}
    
    return 0;
}
