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
	ll n, k;
	cin >> n >> k;
	ll ans;
	if (n == 1) {
		ll a;
		cin >> a;
		ans = k;
		if (a >= ans) --ans;
	} else {
		ll gcd;
		cin >> gcd;
		for (ll i=1; i<n; ++i) {
			ll temp;
			cin >> temp;
			gcd = __gcd(gcd, temp);
		}
		if (gcd==1 || k > (n-1)*(gcd-1)) {
			ans = k + n - 1;
		} else {
			ans = gcd * ((k-1)/(gcd-1)) + ((k-1)%(gcd-1)) + 1;
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
