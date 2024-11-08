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

vl find_all(string s, string m, ll start, ll end) {
	// KMP Algorithm
	ll lps[m.size()];
	ll p_len = 0;
	lps[0] = p_len;
	ll p_i = 1;
	while(p_i < m.size()) {
		if (m[p_i]==m[p_len]) {
			++p_len;
			lps[p_i] = p_len;
			++p_i;
		} else {
			if (p_len == 0) {
				lps[p_i]=0;
				++p_i;
			} else {
				p_len = lps[p_len-1];
			}
		}
	}
	vl ans;
	ll i = start, len = 0;
	while (i<end) {
		if (s[i] == m[len]) {
			++len;
			if(len == m.size()) {
				ans.push_back(i-len+1);
				len = lps[len-1];
			}
			++i;
		} else {
			if (len==0) {
				++i;
			} else {
				len = lps[len-1];
			}
		}
	}
	return ans;
}

void solve() {
	string s;
	cin >> s;
	ll n = s.size();
	if (n<3) {
		print("NO");
		return;
	}
	string s1 = s.substr(0, n/2 + 1);
	string s2 = s.substr(n-n/2-1, n/2+1);
	vl s1_i = find_all(s, s1, 1, n);
	vl s2_i = find_all(s, s2, 0, n-1);
	set<ll> pos_lens;
	for (auto i : s1_i) {
		pos_lens.insert(n-i);
	}
	for(auto i : s2_i) {
		if (pos_lens.contains(n/2+1+i)) {
			print("YES");
			print(s.substr(0, n/2+1+i));
			return;
		}
	}
	print("NO");
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
