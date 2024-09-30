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
	ll k; cin >> k;
	ll n = max<ll>(2, (2*k+1+ll(sqrt(4*k+1)))/2 - 10);
	ll rtn = sqrt(n)-2;
	while(rtn*rtn <= n) ++rtn;
	--rtn;
	for (ll i = 1; i<=20; ++i) {
		if (n - rtn == k) {
			print(n);
			return;
		}
		++n;
		rtn = sqrt(n)-2;
		while(rtn*rtn <= n) ++rtn;
		--rtn;
	}
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
