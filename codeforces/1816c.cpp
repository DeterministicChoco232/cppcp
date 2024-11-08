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
        ll n;cin>>n;
        ll altSum=0;
        for(ll i=0;i<n;++i) {
            ll temp; cin>>temp;
            if(i%2) {altSum+=temp;}
            else {altSum-=temp;}
        }
        cout<<((n%2 || altSum>=0)?"YES\n":"NO\n");
	}
    
    return 0;
}
