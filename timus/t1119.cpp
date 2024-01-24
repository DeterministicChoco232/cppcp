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

void solve() {
	ll N,M,K; cin>>N>>M>>K;
	unordered_set<ll> diags;
	while(K--) {
		ll i,j;
		cin>>i>>j;
		diags.insert((i*1024) ^ j);
	}
	ll grid[N+2][M+2];
	for (ll i=0;i<=N;++i) 
		for (ll j=0;j<=M;++j) 
			grid[i][j] = 0;
	for(ll d=0; d<=min<ll>(N,M); ++d) {
		for(ll i=d; i<=N; ++i) {
			if(diags.count(((i+1)*1024)^(d+1))) {
				grid[i+1][d+1] = max<ll>(grid[i+1][d+1],grid[i][d]+1);
			} else {
				grid[i+1][d] = max<ll>(grid[i][d], grid[i+1][d]);
				grid[i][d+1] = max<ll>(grid[i][d], grid[i][d+1]);
			}
		}
		for(ll j=d+1; j<=M; ++j) {
			if(diags.count(((d+1)*1024)^(j+1))) {
				grid[d+1][j+1] = max<ll>(grid[d+1][j+1],grid[d][j]+1);
			} else {
				grid[d+1][j] = max<ll>(grid[d][j], grid[d+1][j]);
				grid[d][j+1] = max<ll>(grid[d][j], grid[d][j+1]);
			}
		}
	}
	print(ll(0.5+100*(N+M - 0.58578643 * grid[N][M])));
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
