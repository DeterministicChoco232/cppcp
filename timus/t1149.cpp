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

string A(ll n) {
	stringstream s;
	for(ll i=1; i<n; ++i) {
		s << "sin(" << i << (i%2 ? '-' : '+');
	}
	s << "sin(" << n;
	while(n--) {
		s << ')';
	}
	return s.str();
}


void solve() {
	ll n; cin >> n;
	stringstream s;
	for(int i=1;i<n;++i) {
		s << '(';
	}
	for(int i=1;i<n;++i) {
		s << A(i) << '+' << n-i+1 << ')';
	}
	s << A(n) << "+1";
	cout << s.str() << endl;
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
