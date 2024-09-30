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
	ll n, w;
	cin >> n >> w;
	ll terms[n+1];
	terms[0] = -1; // unused
	terms[1] = 0; // dist(n, 1)
	for (ll i = 2; i<=n; ++i) terms[i] = 1; // dist(i-1, i) is guaranteed to have t_i
	ll paths[n+1]; // t_i used for dist(i-1, i) and dist(j-1, j). This stores j for respective t_i
	paths[0] = -1, paths[1] = -1; // unused
	stack<ll> nodes;
	nodes.push(1);
	for(ll i=2; i<=n; ++i) {
		ll cur; cin >> cur;
		while(cur != nodes.top()) {
			terms[i]++;
			paths[nodes.top()] = i;
			nodes.pop();
		}
		nodes.push(i);
	}
	while(nodes.size()>1) {
		terms[1]++;
		paths[nodes.top()] = 1;
		nodes.pop();
	}
	ll fixed = 0;
	ll left = n;
	for(ll _=1; _<n; ++_) {
		ll x, y;
		cin >> x >> y;
		w -= y;
		fixed += 2*y;
		if (--terms[x] == 0) --left;
		if (--terms[paths[x]] == 0) --left;
		cout << fixed + w * left << ' ';
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
