#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n, k;
        cin>>n>>k;
        int m[n][n];
        for(ll i=0; i<n; ++i) {
            for(ll j=0;j<n;++j) {
                cin>>m[i][j];
            }
        }
        ll mn=0;
        for(ll i=0; i<n; ++i) {
            for(ll j=0;j<n;++j) {
                mn+=m[i][j]!=m[n-i-1][n-j-1];
            }
        }
        mn/=2;
        if(mn<k && ((mn-k)%2==0 || n%2)) mn=k;
        cout<<((mn==k)?"YES\n":"NO\n");
	}
    
    return 0;
}
