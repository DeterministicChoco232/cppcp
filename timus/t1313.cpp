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

void solve() {
    ll n;
    cin>>n;
    ll a[n*n];
    for(ll i=0;i<n;++i) {
        ll k=i;
        for(ll j=0;j<n;++j) {
            ll colour;
            cin>>colour;
            ll ind=k*(k+1)/2+j;
            if(k>=n) ind-=(k-n+1)*(k-n+1);
            a[ind]=colour;
            ++k;
        }
    }
    for(ll ans:a) {
        cout<<ans<<' ';
    }
    print();
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
