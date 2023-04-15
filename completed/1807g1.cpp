#include <iostream>
#include <set>
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
        multiset<ll> c;
        for(ll i=0; i<n; ++i) {
            ll temp; cin>>temp;
            c.insert(temp);
        }
        auto it = c.begin();
        if(*(it)!=1) {
            cout<<"NO\n"; continue;
        }
        ll sum=1; bool valid=true;
        while((++it)!=c.end()) {
            if (*it>sum) {
                valid=false;
                break;
            }
            sum+=*it;
        }
        cout<<(valid?"YES\n":"NO\n");
    }
    
    return 0;
}
