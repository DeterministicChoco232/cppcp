// Solving from line 22
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
	ll n; cin >> n;
	ll diagonals[2*n];
	for(ll i=0; i<2*n; ++i) diagonals[i]=0;
	for(ll i=0; i<n; ++i) {
		for (ll j = 0; j<n; ++j) {
			ll a; cin >> a;
			diagonals[j-i+n] = max(diagonals[j-i+n], -a);
		}
	}

	ll ans = 0;
	for(ll i=0; i<2*n; ++i) ans+=diagonals[i];
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
