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
	map<ll, ll> cards;
	for(ll i=0; i<n; ++i) {
		ll a; cin >> a;
		if (cards.contains(a)) {
			cards[a]++;
		} else {
			cards[a]=1;
		}
	}
	vl pf_sum;
	auto it = cards.begin();
	ll sum = it->second;
	pf_sum.push_back(0);
	pf_sum.push_back(sum);
	ll ans = 0;
	while(next(it)!=cards.end()) {
		if(it->first + 1 != (++it)->first) {
			ll j = min<ll>(k, pf_sum.size()-1);
			while(j<pf_sum.size()) {
				ans = max<ll>(ans, pf_sum[j]-pf_sum[max<ll>(j-k, 0)]);
				++j;
			}
			pf_sum.clear();
			sum = it->second;
			pf_sum.push_back(0);
			pf_sum.push_back(sum);
			continue;
		}
		sum += it->second;
		pf_sum.push_back(sum);
	}
	ll j = min<ll>(k, pf_sum.size()-1);
	while(j<pf_sum.size()) {
		ans = max<ll>(ans, pf_sum[j]-pf_sum[max<ll>(j-k, 0)]);
		++j;
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
