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
	ll h, w, xa, ya, xb, yb;
	cin >>h>>w>>xa>>ya>>xb>>yb;
	if(xa>=xb) {
		print("Draw");
	}
	else if(ya==yb) {
		print((xa+xb) % 2? "Alice":"Bob");
	} else {
		ll sign = ((yb>ya)*2-1)*(((xa+xb)%2)*2-1);
		ya += sign*((xb-xa+1)/2);
		yb += sign*((xb-xa)/2);
		ya = min<ll>(w, max<ll>(1, ya));
		yb = min<ll>(w, max<ll>(1, yb));
		if(ya==yb) {
			print((xa+xb) % 2? "Alice":"Bob");
		} else {
			print("Draw");
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
