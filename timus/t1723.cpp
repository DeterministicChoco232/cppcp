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
	char letters[26];
	for(ll i=0; i<26; ++i) {
		letters[i] = 0;
	}
	string inp; cin >> inp;
	for (char c:inp) {
		++letters[c-'a'];
	}
	char o = 'a'; ll max=letters[0];
	for (ll i = 0; i < 26; ++i) {
		if (max < letters[i]) {
			max = letters[i];
			o='a'+i;
		}
	}
	cout << o << endl;
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
