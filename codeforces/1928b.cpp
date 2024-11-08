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
	set<ll> a;
	ll n; cin >> n;
	for(ll _=0; _<n; ++_) {
		ll temp;
		cin>>temp;
		a.insert(temp);
	}

	ll ans = 0;
	ll cur_range = 0;
	auto i = a.begin();
	auto j = a.begin();
	while(i != a.end()) {
		while(j != a.end() && *j - *i < n) {
			++j;
			cur_range +=1;
		}
		ans = max(ans, cur_range);
		++i;
		cur_range -= 1;
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
