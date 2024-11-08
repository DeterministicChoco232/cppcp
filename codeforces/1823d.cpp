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
ll s_i = 0;
char stall() {
	s_i = (s_i+1)%3;
	return "xyz"[s_i];
}

void solve() {
    ll n,k;
    cin>>n>>k;
    ll x[k],c[k];
    for(ll j=0;j<k;++j)cin>>x[j];
    for(ll j=0;j<k;++j)cin>>c[j];
	string s = "xyz";
	s.reserve(n);
	s_i = 2;
	ll count = 3;
	char p_c = 'a';
    for(ll j=0;j<k;++j) {
		if(x[j] - s.length() < c[j]-count) {
			print("NO");
			return;
		} else {
			for(ll _ = count; _ < c[j]; ++_) {
				s.push_back(p_c);
			}
			for(ll _ = s.length(); _ < x[j]; ++_) {
				s.push_back(stall());
			}
			count = c[j];
			++p_c;
		}
	}
	print("YES");
	print(s);
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
