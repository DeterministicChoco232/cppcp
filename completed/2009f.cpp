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
	ll sum[n+1];
	sum[0]=0;
	for(ll i=1;i<=n;++i) {
		ll temp;
		cin >> temp;
		sum[i]=sum[i-1]+temp;
	}
	while(q--) {
		ll l, r;
		cin >> l >> r;
		l--; r--;
		ll ls = l/n, rs = r/n;
		l %= n;
		r %= n;
		ll ans = sum[n]*(rs-ls);
		ans -= sum[rs];
		if (r<n-rs) {
			ans += sum[rs+r+1];
		} else {
			ans += sum[n]+sum[r+rs-n+1];
		}
		l--;
		ans += sum[ls];
		if (l<n-ls) {
			ans -= sum[ls+l+1];
		} else {
			ans -= sum[n]+sum[l+ls-n+1];
		}
		print(ans);
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
