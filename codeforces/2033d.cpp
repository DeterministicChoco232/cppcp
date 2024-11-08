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
	ll n; cin>>n;
	set<ll> p;
	ll sum=0;
	p.insert(sum);
	ll ans = 0;
	for (ll i=1; i<=n; ++i) {
		ll a; cin >> a;
		sum+=a;
		if (p.contains(sum)) {
			ans +=1;
			p.clear();
		}
		p.insert(sum);
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
