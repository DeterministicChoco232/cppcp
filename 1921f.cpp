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
	ll n, q;
	cin >> n >> q;
	ll a[n];
	for(ll i=0; i<n; ++i) {
		cin>>a[i];
	}
	stringstream ss;
	while(q--) {
		ll s, d, k;
		cin >> s >> d >> k;
		ll ans=0;
		// naive O(n*q) solution
		for(ll i=0; i<k; ++i) {
			ans += (i+1) * a[s+i*d-1];
		}
		ss << ans << ' ';
	}
	print(ss.str());
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
