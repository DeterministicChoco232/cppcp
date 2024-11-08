// solve function on line 22
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
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
	ll x, n; cin >> x >> n;
	ll ans=1;
	for(ll i=1;i*i<=x; ++i) {
		if(x%i == 0) {
			ll factor1=i, factor2=x/i;
			if(factor1*n<=x) {
				ans=max<ll>(ans, factor1);
			}
			if(factor2*n<=x) {
				ans=max<ll>(ans, factor2);
			}
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
