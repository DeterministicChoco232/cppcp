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
ll dfs(vector<set<ll>> &graph, vl &paths, ll path_length, ll cur) {
	for (ll node : graph[cur]) {
		if (paths[node] != -1) {
			if (paths[node] != 0 && paths[node] != cur) {
				print("YES");
				print(path_length+4);
				print(cur, node);
				return paths[node];
			}
		} else {
			auto next = dfs(graph, paths, path_length + 1, node);
			if (next != -1) {
				print(cur, node);
				return next;
			}
		}
	}

	return -1;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<set<ll>> graph;
	for(ll i=0; i<=n; ++i) {
		set<ll> s = {};
		graph.push_back(s);
	}
	for(ll i=1; i<=m; ++i) {
		ll node1, node2;
		cin >> node1 >> node2;
		graph[node1].insert(node2);
		graph[node2].insert(node1);
	}
	set<ll> four_edges;
	for(ll i=1; i<=n; ++i) {
		if (graph[i].size() >= 4) {
			four_edges.insert(i);
		}
	}
	for(ll four_edge : four_edges) {
		vl paths;
		for( ll i=0; i<=n; ++i) {
			paths.push_back(-1);
		}
		ll path_count = 0;
		ll path_length = 0;
		paths[four_edge] = path_count;
		for(ll node : graph[four_edge]) {
			++path_count;
			paths[node] = path_count;
		}
		for(ll node : graph[four_edge]) {
			auto ans = dfs(graph, paths, path_length + 1, node);
			if (ans != -1) {
				print(four_edge, node);
				ll count = 0;
				for(ll left : graph[four_edge]) {
					if (left != node) {
						if (paths[left] == ans) {
							print(four_edge, left);
						} else {
							if (count < 2) {
								++count;
								print(four_edge, left);
							}
						}
					}
				}
				return;
			}
		}
	}
	print("NO");
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
