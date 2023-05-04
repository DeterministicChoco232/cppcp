#include <bits/stdc++.h>
#define TEST_CASES
using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void solve() {
    ll n,k;
    cin>>n>>k;
    ll x[n],c[n];
    for(ll j=0;j<k;++j)cin>>x[j];
    for(ll j=0;j<k;++j)cin>>c[j];
    cout<<k<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll inf=1e18;

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
