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
	ll n; cin >> n;
	ll last_a, max_l[n+1];
	cin>>last_a; max_l[1]=-1;
	for(ll i=2; i<=n; ++i) {
		ll a; cin >> a;
		if(a == last_a) {
			max_l[i]=max_l[i-1];
		} else {
			max_l[i]=i-1;
		}
		last_a = a;
	}

	ll q; cin >> q;
	while(q--) {
		ll l, r;
		cin >> l >> r;
		if (max_l[r] < l) {
			print(-1, -1);
		} else {
			print(max_l[r], r);
		}
	}
	print();
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
