// solve function on line 22
#include <bits/stdc++.h>

using ll = long long;
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
	ll rsize = 1024;
    ll n,m, max_depth=0;
    cin>>n>>m;
    ll a[n][m];
    for(ll i=0; i<n; ++i) {
	    for(ll j=0; j<m; ++j) {
			cin>>a[i][j];
		}
	}
    unordered_set<ll> checked;
    for(ll i=0; i<n; ++i) {
	    for(ll j=0; j<m; ++j) {
		    if (checked.count(i*rsize ^ j) | a[i][j] == 0) continue;
		    ll cur_depth = 0;
		    queue<ll> to_check;
			to_check.push(i*rsize^j);
			while(!to_check.empty()) {
				ll cur = to_check.front();
				to_check.pop();
				if (checked.count(cur) | a[cur/rsize][cur%rsize] == 0) continue;
				checked.insert(cur);
				cur_depth += a[cur/rsize][cur%rsize];
				if(cur%rsize>0) to_check.push(cur-1);
				if(cur%rsize+1<m) to_check.push(cur+1);
				if(cur/rsize>0) to_check.push(cur-rsize);
				if(cur/rsize+1<n) to_check.push(cur+rsize);
			}
			max_depth = max<ll>(max_depth, cur_depth);
	    }
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
