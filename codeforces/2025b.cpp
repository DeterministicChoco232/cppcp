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

void solve() {
	ll t;
	cin >> t;
	for (ll i=0; i<t; ++i) {
		ll dump;
		cin >> dump;
	}
	ll ans[100001];
	ans[0] = 1;
	for (ll i = 1; i<100001; ++i) {
		ans[i] = (2*ans[i-1]) % (1000000007);
	}
	for (ll i=0; i<t; ++i) {
		ll k;
		cin >> k;
		print(ans[k]);
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
