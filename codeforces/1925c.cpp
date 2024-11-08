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
	ll n, k, m; cin >> n >> k >> m;
	string s, missing = ""; cin >> s;
	missing.reserve(n);
	unordered_set<char> distinct_chars;
	ll na = 0;
	for(ll i=0; i<m; ++i) {
		distinct_chars.insert(s[i]);
		if(distinct_chars.size() == k) {
			missing += s[i];
			++na;
			if(na == n) {
				print("YES");
				return;
			}
			distinct_chars.clear();
		}
	}
	print("NO");
	char missingchar = 'a';
	while(distinct_chars.count(missingchar)) {
		++missingchar;
	}
	missing+=missingchar;
	for( ll _=missing.length(); _<n; ++_)
		missing.push_back('a');
	print(missing);
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
