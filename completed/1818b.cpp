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
        ll n;
        cin>>n;
        if (n%2) {
            if(n==1) {
                cout<<"1\n";
            } else {
                cout<<"-1\n";
            }
        } else {
            for(ll i=0;i<n;++i) {
                if(i%2) {
                    cout<<n-i+1<<' ';
                } else {
                    cout<<n-i-1<<' ';
                }
            }
            cout<<'\n';
        }
	}
    
    return 0;
}
