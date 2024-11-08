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
        ll ans = 0;
        for(ll i=0;i<n;++i) {
            ll temp; cin>>temp;
            ans = (ans | temp) - (ans & temp);
        }
        
        cout << ((n%2==0&&ans!=0)?-1:ans) << '\n';
    }
    
    return 0;
}
