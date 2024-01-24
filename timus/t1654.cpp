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
	list<char> s; char c;
	while(cin>>c) {
		s.push_back(c);
	}
	if (s.size()>1) {
		auto it = s.begin();
		while(next(it, 1) != s.end() && next(it, 2) != s.end()) {
			if(*next(it, 1) == *next(it, 2)) {
				s.erase(next(it, 1), next(it, 3));
				if(it != s.begin()) {
					--it;
				}
			} else {
				++it;
			}
		}
		if(s.size()>1 && *s.begin()==*next(s.begin(), 1)) {
			s.erase(s.begin(), next(s.begin(),2));
		}
	}
	for (char c:s) {
		cout<<c;
	}
	cout<<endl;
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
