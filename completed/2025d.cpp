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
	ll n, m; cin >> n >> m;
	ll msofar = 0;
	vector<map<ll, ll>> S, I;
	ll s_count[m];
	for (ll i=0; i<n; ++i) {
		ll r; cin >> r;
		if (r==0) {
			S.push_back({});
			I.push_back({});
			s_count[msofar]=0;
			++msofar;
		} else if (abs(r) <= msofar) {
			if (r>0) {
				if (I.rbegin()->contains(r)) {
					(*I.rbegin())[r]++;
				} else {
					(*I.rbegin())[r] = 1;
				}
			} else {
				s_count[msofar-1]++;
				if (S.rbegin()->contains(-r)) {
					(*S.rbegin())[-r]++;
				} else {
					(*S.rbegin())[-r] = 1;
				}
			}
		}
	}
	vl prev = {0}, cur;
	for(ll i=1; i<=m; ++i) {
		ll satisfying = s_count[i-1];
		auto s_it = S[i-1].rbegin();
		auto i_it = I[i-1].begin();
		for(ll j=0; j<=i; j++) {
			if (i_it != I[i-1].end() && j >= i_it -> first) {
				satisfying+=i_it->second;
				i_it++;
			}
			if (s_it != S[i-1].rend() && i-j < s_it -> first) {
				satisfying-=s_it->second;
				s_it++;
			}
			cur.push_back(satisfying + max(prev[max<ll>(0, j-1)], prev[min(j, i-1)]));
		}
		prev.clear();
		swap(prev, cur);
	}
	ll ans = prev[0];
	for(ll i=1; i<=m; ++i) {
		ans = max(ans, prev[i]);
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
