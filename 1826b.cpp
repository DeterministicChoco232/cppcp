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
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n;++i)
        cin>>a[i];
    ll ans=1;
    for(ll i=0; i<n/2;++i) {
        ll diff=abs(a[i]-a[n-i-1]);
        ans=(ans*diff)/__gcd(ans, diff);
    }
    if(n==1) ans=0;
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
