#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
const ll inf=1e18;

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
