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
	ll n;
	cin >> n;
	map<ll, ll> count;
	for(ll _=0; _<n; ++_) {
		ll temp; cin >> temp;
		if(count.contains(temp)) {
			++count[temp];
		} else {
			count[temp] = 1;
		}
	}
	ll ans = 0;
	for (auto key_value : count) {
		ll num_count = key_value.second;
		ans += num_count * (num_count - 1) * (num_count - 2);
	}
	// naive O(n*sqrt(a)) solution
	for(ll b=2; b*b < 1e9; ++b) {
		for(auto key_value : count) {
			ll num = key_value.first;
			ll num_count = key_value.second;
			if (num % (b*b) == 0) {
				ll j_num = num / b;
				ll i_num = j_num / b;
				if (count.contains(i_num) && count.contains(j_num)) {
					ans += num_count * count[i_num] * count[j_num];
				}
			}
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
