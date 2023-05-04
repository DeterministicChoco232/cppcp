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
        ll n;cin>>n;
        if (n==1) {
            cout<<"1\n";
            continue;
        }
        if (n%2==1) {
            cout<<"-1\n";
            continue;
        }
        for(ll i=0;i<n;++i)
            cout<<((i%2)?i:n-i)<<' ';
        cout<<'\n';
	}
    
    return 0;
}
