#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n,m; cin>>n>>m;
        ll a, b, c;
        set<ll> k;
        for(ll i=0;i<n;++i) {
            ll temp; cin>>temp;
            k.insert(temp);
        }
        for(ll j=0;j<m;++j) {
            cin>>a>>b>>c;
            bool ans=false;
            if (c>0) {
                auto b_index = k.lower_bound(b);
                ll potentialLine;
                if(b_index==k.end()) {
                    potentialLine=*prev(b_index);
                } else {
                    potentialLine=*b_index;
                    if (b_index!=k.begin() && b - *prev(b_index) < *b_index - b) {
                        potentialLine=*prev(b_index);
                    }
                }
                if(abs(b-potentialLine) < 2*sqrt(a*c)) {
                    ans=true;
                    cout<<"Yes\n"<<potentialLine<<'\n';
                }
            }
            if(!ans) cout<<"No\n";
        }
    cout << '\n';
	}
    return 0;
}
