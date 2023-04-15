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
        cout<<2*n-1<<' ';
        for(ll i=1;i<n;++i) {
            if(i%2) {
                cout<<1+i<<' ';
            } else {
                cout<<n+i-0<<' ';
            }
        }
        cout<<'\n';
        for(ll i=1;i<n;++i) {
            if(i%2) {
                cout<<i<<' ';
            } else {
                cout<<n+i-1<<' ';
            }
        }
        cout<<2*n<<'\n';
	}
    
    return 0;
}
