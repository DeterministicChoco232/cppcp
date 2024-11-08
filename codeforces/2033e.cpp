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
	ll p[n+1];
	p[0]=0;
	for(ll i=1; i<=n;++i) {
		cin>>p[i];
	}
	ll indexes[n+1];
	for(ll i=0; i<=n;++i) {
		indexes[p[i]]=i;
	}
	ll swaps=0;
	for(ll i=1; i<=n;++i) {
		if(p[p[i]]!=i) {
			swaps +=1;
			ll temp = p[p[i]];
			p[p[i]]=i;
			p[indexes[i]]=temp;
			indexes[temp]=indexes[i];
			indexes[i]=p[i];
		}
	}
	print(swaps);
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
