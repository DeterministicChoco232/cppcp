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
	ll N, M; cin >> N;
	unordered_map<int, int> d;
	while(N--) {
		ll curd; cin >> curd;
		if(d.count(curd)) {
			++d[curd];
		} else {
			d[curd]=1;
		}
	}
	cin >> M;
	ll score = 0;
	while(M--) {
		ll curd; cin >> curd;
		if(d.count(curd)) {
			++score;
		}
	}
	cout << score << endl;
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
