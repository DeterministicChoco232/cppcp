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
        ll n, k;
        cin>>n>>k;
        string me;
        cin>>me;
        ll left=1;
        for(ll i=1;i<n;++i) {
            string temp;
            cin>>temp;
            left+=(temp==me);
        }
        cout<<left<<'\n';
	}
    
    return 0;
}
