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

void solve() {
	ll w,h,n;
	cin >>h>>w>>n;
	ld l=0, curlen=w;
	while(n--) {
		string s; cin >> s;
		if (s.length() + curlen <= w) {
			curlen += s.length()+1;
		} else {
			++l;
			curlen=s.length()+1;
		}
	}
	cout<<ll(ceil(l/h))<<endl;
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
