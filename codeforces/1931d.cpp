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
	ll n, x, y; cin >> n >> x >> y;
	ll ans = 0;
	map<pll, ll> m;
	for( ll i=0; i<n; ++i) {
		ll cur; cin >> cur;
		pll opp = pll((x-(cur%x))%x, cur%y);
		pll me = pll(cur%x, cur%y);
		if(m.count(opp)) {
			ans += m[opp];
		}
		if(m.count(me)) {
			++m[me];
		} else {
			m[me] = 1;
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
