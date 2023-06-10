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
    ll n,m;
    cin>>n>>m;
    ll candidates[n];
    for(ll i=0;i<n;++i)
        candidates[i]=0;
    for(ll i=0;i<m;++i) {
        ll s;
        cin>>s;
        ++candidates[s-1];
    }

    for(ll i=0;i<n;++i) {
        cout<<(100.0*candidates[i])/m<<'%'<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(2);

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
