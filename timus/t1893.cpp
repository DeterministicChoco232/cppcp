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
	ll n; char s; string out;
	cin >> n >> s;
	if (n < 3) {
		if (unordered_set<char>{'A', 'D'}.count(s)) {
			out="window";
		} else {
			out="aisle";
		}
	} else if (n < 21) {
		if (unordered_set<char>{'A', 'F'}.count(s)) {
			out="window";
		} else {
			out="aisle";
		}
	} else {
		if (unordered_set<char>{'A', 'K'}.count(s)) {
			out="window";
		} else if (unordered_set<char>{'C', 'D', 'G', 'H'}.count(s)) {
			out="aisle";
		} else {
			out = "neither";
		}
	}

	cout << out << endl;
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
