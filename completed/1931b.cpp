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
	ll n; cin >>n;
	ll a[n];
	ll sum = 0;
	for(ll i=0; i<n; ++i) {
		cin>>a[i];
		sum += a[i];
	}
	ll avg = sum/n;
	ll req = 0;
	bool possible=true;
	for(ll i=n-1; i>=0; --i) {
		req += avg-a[i];
		if (req<0) possible = false;
	}
	print(possible? "YES": "NO");
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
