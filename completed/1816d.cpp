#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n; cin>>n;
        ll temp;
        cout<<"+ "<<n<<"\n+ "<<n+1<<endl;
        cin>>temp;
        cin>>temp;
        ll reverseMap[n], identity[n], maxDiff=0;
        vector<pair<ll, ll>> unresolved;
        unresolved.reserve(n/2);
        for(ll i=0;i<n;++i) identity[i]=0;
        for(ll i=0;i<n;++i) reverseMap[i]=0;
        for(ll i=2;i<=n;++i) {
            cout<<"? "<<1<<' '<<i<<endl;
            ll diff;
            cin>>diff;
            if(identity[diff]) {
                unresolved.push_back({diff, i});
            } else {
                identity[diff]=i;
                maxDiff=max(diff,maxDiff);
            }

        }
        reverseMap[maxDiff]=1;
        reverseMap[0]=identity[maxDiff];
        for(auto unres : unresolved) {
            cout<<"? "<<reverseMap[0]<<' '<<unres.second<<endl;
            ll diff; cin>>diff;
            reverseMap[diff]=unres.second;
            reverseMap[2*maxDiff-diff]=identity[unres.first];
        }
        for(ll i=1;i<n;++i) {
            if(!reverseMap[maxDiff-i]) reverseMap[maxDiff-i]=identity[i];
        }
        ll ans[2*n];
        for(ll i=0;i<n;++i) {
            ans[reverseMap[i]-1]=((i%2)?(i+1)/2:n-i/2);
            ans[n+reverseMap[n-1-i]-1]=((i%2)?(i+1)/2:n-i/2);
        }
        cout<<"! ";
        for(ll i=0;i<2*n;++i) {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        cin>>temp;

	}
    
    return 0;
}
