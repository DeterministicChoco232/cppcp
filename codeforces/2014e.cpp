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
	ll n, m, h;
	cin >> n >> m >> h;
	unordered_set<ll> a;
	for(ll i=0; i<h; ++i) {
		ll temp;
		cin >> temp;
		a.insert(temp);
	}
	unordered_map<ll, ll> edges[n+1];
	for (ll i=1; i<=m; ++i) {
		ll u, v, w;
		cin >> u >> v >> w;
		edges[u][v] = w;
		edges[v][u] = w;
	}
	unordered_set<ll> marian_visited;
	unordered_set<ll> marian_horse_visited;
	unordered_set<ll> robin_visited;
	unordered_set<ll> robin_horse_visited;
	map<ll, vector<tuple<bool, ll, bool>>> to_check; // robin?, node, horse?
	to_check[0].push_back({false, 1, false});
	to_check[0].push_back({true, n, false});
	for (auto& [time, events] : to_check) {
		for (auto event : events) {
			bool robin = get<0>(event);
			ll node = get<1>(event);
			bool horse = get<2>(event) || a.contains(node);
			if ((robin && marian_visited.contains(node)) || (!robin && robin_visited.contains(node))) {
				print(time);
				return;
			}
			if (marian_horse_visited.contains(node) || robin_horse_visited.contains(node) || 
					((marian_visited.contains(node) || robin_visited.contains(node)) && !horse)) {
				continue;
			}
			if (robin) {
				if (horse) {
					robin_horse_visited.insert(node);
				}
				robin_visited.insert(node);
			} else {
				if (horse) {
					marian_horse_visited.insert(node);
				}
				marian_visited.insert(node);
			}
			for (auto& [my_edge, travel_time] : edges[node]) {
				to_check[time+travel_time/(1+int(horse))].push_back({robin, my_edge, horse});
			}
		}
	}
	print(-1);
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
