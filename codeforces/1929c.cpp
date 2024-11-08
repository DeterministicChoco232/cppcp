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
	ll k, x, a;
	cin >> k >> x >> a;
	ll target = a+1;
	k-=1;
	ll left = a;
	bool pos = true;
	for(ll i=0; i<=x; ++i) {
		left -= (target-left)/k + ((target-left)%k!=0);
		if (left<0) {
			pos=false;
			break;
		}
	}
	print(pos?"YES":"NO");
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
