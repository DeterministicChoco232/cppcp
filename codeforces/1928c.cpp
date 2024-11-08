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
	ll n, x; cin >> n >> x;
	if((x+n)%2) {
		print(0);
		return;
	}
	set<ll> factors;
	ll x1 = (n-x)/2;
	for(ll f=1; f*f<=x1; ++f) {
		if (x1%f == 0) {
			if(   f>=x-1)factors.insert(f);
			if(x1/f>=x-1)factors.insert(x1/f);
		}
	}
	ll x2 = (n+x)/2-1;
	for(ll f=1; f*f<=x2; ++f) {
		if (x2%f == 0) {
			if(   f>=x-1)factors.insert(f);
			if(x2/f>=x-1)factors.insert(x2/f);
		}
	}
	print(factors.size());
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
