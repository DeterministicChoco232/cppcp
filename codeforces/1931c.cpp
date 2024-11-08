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
	ll n; cin >> n;
	ll a[n]; cin>>a[0];
	ll first_length = 1;
	bool same=true;
	for(ll i=1; i<n; ++i) {
		cin >> a[i];
		if(same && a[i] == a[0]) {
			++first_length;
		} else {
			same = false;
		}
	}
	if(first_length == n) {
		print(0);
		return;
	}
	ll last_length = 1;
	same=true;
	for(ll i=n-2; i>=0; --i) {
		if(same && a[i] == a[n-1]) {
			++last_length;
		} else {
			same = false;
			break;
		}
	}
	if(a[0]==a[n-1]) {
		print(n-first_length-last_length);
	} else {
		print(n-max(first_length, last_length));
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
