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
void change_count(unordered_map<ll, ll>& counts, map<ll, unordered_set<ll>>& instances, ll num, ll change) {
	if (instances.contains(counts[num]) && instances[counts[num]].contains(num)) {
		instances[counts[num]].erase(num);
		if(instances[counts[num]].empty()) {
			instances.erase(counts[num]);
		}
	}
	counts[num]+=change;
	if (!instances.contains(counts[num])) {
		instances[counts[num]] = {};
	}
	instances[counts[num]].insert(num);
}

void solve() {
	ll n, k, q;
	cin >> n >> k >> q;
	ll b[n];
	unordered_map<ll, ll> counts;
	map<ll, unordered_set<ll>> instances;
	for(ll i=0; i<n; ++i) {
		ll temp;
		cin >> temp;
		b[i] = temp-i;
		counts[b[i]] = 0;
	}
	ll l_insertions[n], r_insertions[n];
	for(ll i=0; i<k-1; ++i) {
		change_count(counts, instances, b[i], 1);
		l_insertions[i]=inf;
	}
	for(ll i=k-1; i<n;++i) {
		
		change_count(counts, instances, b[i], 1);
		l_insertions[i] = k-(instances.rbegin()->first);
		change_count(counts, instances, b[i-k+1], -1);
	}
	instances.clear();
	for(ll i=0; i<n; ++i) {
		counts[b[i]] = 0;
	}
	for(ll i=n-1; i>n-k; --i) {
		change_count(counts, instances, b[i], 1);
		r_insertions[i]=inf;
	}
	for(ll i=n-k; i>=0; --i) {
		change_count(counts, instances, b[i], 1);
		r_insertions[i] = k-(instances.rbegin()->first);
		change_count(counts, instances, b[i+k-1], -1);
	}


	for(ll _=0; _<q; ++_) {
		ll l, r;
		cin >> l >> r;
		print(min<ll>(l_insertions[r-1], r_insertions[l-1]));
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
