#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n; cin>>n;
        ll a[n], b[n], bSum[n+1];bSum[0]=0;
        for(ll i=0;i<n;++i) {
            cin>>a[i];
        }
        for(ll i=0;i<n;++i) {
            cin>>b[i];
            bSum[i+1]=b[i]+bSum[i];
        }
        vector<ll> teaEnds[n+1];
        for(ll i=0;i<n;++i) {
            ll target=a[i]+bSum[i];
            ll targetIndex=distance(bSum, lower_bound(bSum+i+1, bSum+n+1, target))-1;
            teaEnds[targetIndex].push_back(i);
        }
        ll empty=0;
        for(ll i=0;i<n;++i) {
            empty+=teaEnds[i].size();
            ll ans=(i+1-empty)*b[i];
            for(ll j=0;j<teaEnds[i].size();++j) {
                ans+=a[teaEnds[i][j]];
                //subtracting what has been drunk already
                ans-=bSum[i]-bSum[teaEnds[i][j]];
            }
            cout<<ans<<' ';
        }

        cout << '\n';
    }
    
    return 0;
}
