#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

	ll t;
	cin >> t;
    ll inf=99;
    while(t--) {
        ll n, k; cin>>n>>k;
        ll ts=n*(n+1)/2,ns=ts-k; //total and negative subarrays
        ll v=0;
        while (v*(v+1)<=2*ns) ++v; --v;
        ll nInf=n-v-1; // number of infinites
        if(v*(v+1)/2==ns) {
            for(ll i=0;i<=nInf;++i) cout<<inf<<' ';
            for(ll i=0;i<v;++i) cout<<"-2 ";
            cout<<'\n';
            continue;
        }
        ll u=(v+1)-(ns-v*(v+1)/2);
        for(ll i=0;i<n-v-1;++i) cout<<inf<<' ';
        cout<<2*u-1;
        for(ll i=0;i<v;++i) cout<<" -2";
        cout<<'\n';
    }
    
    return 0;
}
