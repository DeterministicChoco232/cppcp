// Solving from line 13
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
const ll inf=1e18;

#define TEST_CASES
void solve() {
	ll n, k;
	ll mod = 1000000007;
	cin >> n >> k;
	if (k==1) {
		println("{}", n%mod);
		return;
	}
	// Based around Pisano Period
	// Fibonacci numbers mod k repeat after at most 6k so O(k)
	vector<ll> fib;
	fib.resize(6*k+2);
	fib[0] = 0, fib[1] = 1;
	ll repeat=-1, zeroes = 0;
	for(ll i=2; i<=6*k+1; ++i) {
		fib[i] = (fib[i-2] + fib[i-1]) % k;
		if(fib[i] == 0) ++zeroes;
		if (fib[i] == 1 && fib[i-1] == 0) {
			repeat = i-1;
			break;
		}
	}
	ll remaining = n % zeroes;
	ll ans = ((n/zeroes) % mod) * repeat;
	for(ll i=1; i<=6*k; ++i) {
		if(remaining==0) break;
		++ans;
		if(fib[i]==0) --remaining;
	}
	println("{}", ans%mod);
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
