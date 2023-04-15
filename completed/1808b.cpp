#include <iostream>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n,m;
        cin >> n >> m;
        multiset<ll> game[m];
        for(int i=0;i<n;++i) {
            for(int j=0;j<m; ++j) {
                ll temp; cin>>temp;
                game[j].insert(temp);
            }
        }
        ll sum=0;
        for(int j=0;j<m;++j) {
            ll mult=1-n;
            for(auto i=game[j].begin(); i!=game[j].end();++i) {
                sum+=(*i)*mult;
                mult+=2;
            }
        }
        cout << sum << '\n';
    }
    
    return 0;
}
