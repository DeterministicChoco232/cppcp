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
	ll N, M, Y; cin >> N >> M >> Y;
	bool exist = false;
	for (ll X = 0; X < M; X++) {
		// Calculating X^N % M
		ll num = 1, n=N, powX = X;
		while ( n!=0 ) {
			if (n%2) {
				num = (num * powX) % M;
			}
			n/=2;
			powX = (powX * powX) % M;
		}
		if (num == Y) {
			exist = true;
			cout << X << ' ';
		}
	}
	if (!exist) { cout << -1; }
	cout << endl;
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
