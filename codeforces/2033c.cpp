// Solving from line 22
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
	ll a[n];
	for(ll i=0; i<n; ++i) {
		cin >> a[i];
	}
	ll d = 0;
	for(ll i=0; i<n/2; ++i) {
		d+=min((a[i]==a[i+1])+(a[n-i-1]==a[n-i-2]), (a[i]==a[n-i-2])+(a[i+1]==a[n-i-1]));
	}
	if(n%2==0) {
		d-=(a[n/2]==a[n/2-1]);
	}
	print(d);
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
