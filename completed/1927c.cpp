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
	ll n, m, k;
	cin >> n >> m >> k;
	bool a[k+1], b[k+1];
	for(ll i=1; i<=k; ++i)
		a[i]=false;
	for(ll i=1; i<=k; ++i)
		b[i]=false;
	ll a_count = 0;
	for(ll _=0; _<n; ++_) {
		ll temp; cin >> temp;
		if(temp<=k && !a[temp]) {
			++a_count;
			a[temp]=true;
		}
	}
	ll dup_count = 0, b_count = 0;
	for(ll _=0; _<m; ++_) {
		ll temp; cin >> temp;
		if(temp<=k && !b[temp]) {
			++b_count;
			b[temp]=true;
			if(a[temp]) {
				++dup_count;
				--a_count;
				--b_count;
			}
		}
	}
	for(ll i=1; i<=k; ++i) {
		if(!(a[i] || b[i])) {
			print("NO");
			return;
		}
	}
	if(min(a_count, k/2) + min(b_count, k/2) + dup_count < k) {
		print("NO");
	} else {
		print("YES");
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
