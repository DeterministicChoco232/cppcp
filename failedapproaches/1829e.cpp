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
 	/* This would not work on a test case such as:
	   2 3
	   0 1 1
	   1 1 1
	*/
	ll n,m; cin >> n >> m;
	vector<ll> l, last, cur;
	last.reserve(m);
	cur.reserve(m);
	l.reserve(m*n/2 +1);

	for(ll j=0;j<n;++j) {
		swap(last, cur);
		cur.clear();
		for(ll i=0;i<m;++i) {
			ll cur_cell; cin >> cur_cell;
			if(cur_cell == 0) {
				cur.push_back(-1);
				continue;
			}
			if(j!=0 && last[i] != -1) {
				l[last[i]] += cur_cell;
				if(i!=0 && cur[i-1] != -1) {
					cur.push_back(cur[i-1]);
					if(cur[i] != last[i])
						l[cur[i]] += l[last[i]];
				} else {
					cur.push_back(last[i]);
				}
			} else {
				if(i!=0 && cur[i-1] != -1) {
					cur.push_back(cur[i-1]);
					l[cur[i]] += cur_cell;
				} else {
					cur.push_back(l.size());
					l.push_back(cur_cell);
				}
			}
		}
	}

	ll max_depth=0;
	for(ll depth:l) {
		max_depth = max<ll>(max_depth, depth);
	}
	print(max_depth);
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
