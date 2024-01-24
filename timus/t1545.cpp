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
	ll n; cin >> n;
	unordered_map<char, vector<string>> a;
	while (n--) {
		string s; cin >> s;
		if (!a.count(s[0])) {
			a[s[0]] = vector<string>();
		}
		a[s[0]].push_back(s);
	}
	char i; cin >> i;
	if (a.count(i)) {
		for (auto s : a[i]) {
			cout << s << endl;
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
