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
	ll n, m; cin >> n >> m;
	map<ll, vl> mp;
	for(ll i=0; i<n; ++i) {
		string s; cin >> s;
		ll k=0;
		while(s[s.length()-k-1] == '0') ++k;
		mp[k].push_back(s.length());
	};
	ll sl = 0;
	bool anna_turn=true;
	for(auto it = mp.rbegin(); it!=mp.rend(); ++it) {
		for(auto e:it->second) {
			if(anna_turn) {
				sl += e - it->first;
			} else {
				sl += e;
			}
			anna_turn = not anna_turn;
		}
	}
	print(sl > m? "Sasha" : "Anna");
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
