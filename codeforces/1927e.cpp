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
	ll n, k; cin >> n >> k;
	ll a[n+1];
	ll min_left = 1, max_left = n;
	bool cur_min = true;
	for(ll i=0; i<=n; ++i) a[i]=-1;

	for(ll i=1; i<=n; ++i) {
		if(a[i] == -1) {
			if(cur_min) {
				for(ll j=i; j<=n; j+=k) {
					a[j] = min_left;
					++min_left;
				}
			} else {
				for(ll j=i; j<=n; j+=k) {
					a[j] = max_left;
					--max_left;
				}
			}
			cur_min = !cur_min;
		}
	}

	for (ll i = 1; i<=n; ++i) {
		cout << a[i] << ' ';
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
