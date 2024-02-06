// solve function on line 22
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
const ll inf=1e18;

void print() {
    cout<<'\n';
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    cout << t << ' ';
    print(std::forward<Args>(args)...);
}

#define TEST_CASES
void solve() {
    ll n; cin>>n;
    ll diff[n/2];
    for(ll i=0;i<n/2;++i) {
	    cin>>diff[i];
    }
    ll dump;
    if(n%2) cin >> dump;
    for(ll i=n/2 - 1;i>=0;--i) {
	    ll cur; cin>>cur;
	    diff[i]=abs<ll>(cur-diff[i]);
    }
    bool zero = true;
    for(ll i:diff) {
	    if (i!=0) {
		    zero=false;
		    break;
	    }
    }
    if(zero) {
	    print(0);
	    return;
    }
    ll ans = diff[0];
    for (ll i=1; i<n/2; ++i) {
	    if (diff[i]) {
		    ans=gcd(ans, diff[i]);
	    }
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(6);

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
