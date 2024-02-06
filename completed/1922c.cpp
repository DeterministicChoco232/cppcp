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
	ll a[n], l_p[n+1], r_p[n+1];
	for(ll i=0;i<n;++i) {
		cin>>a[i];
	}
	l_p[0]=0, l_p[1]=0;
	r_p[0]=0; r_p[n]=0;
	ll curd,prevd=inf;
	for(ll i=1; i<n; ++i) {
		l_p[i+1]=l_p[i];
		curd=a[i]-a[i-1];
		if(curd<prevd) {
			++l_p[i+1];
		} else {
			l_p[i+1] += curd;
		}
		prevd=curd;
	}
	prevd=inf;
	for(ll i=n-2; i>=0; --i) {
		r_p[i+1]=r_p[i+2];
		curd=a[i+1]-a[i];
		if(curd<prevd) {
			++r_p[i+1];
		} else {
			r_p[i+1] += curd;
		}
		prevd=curd;
	}
	ll m; cin>>m;
	while(m--) {
		ll x,y; cin>>x>>y;
		if(x<y) {
			print(l_p[y]-l_p[x]);
		} else {
			print(r_p[y]-r_p[x]);
		}
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
