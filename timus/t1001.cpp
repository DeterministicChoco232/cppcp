#include <bits/stdc++.h>
#define print(x) cout<<x<<'\n'
using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void solve() {
    stack<long double> root;
    ll num;
    while(cin>>num) {
        root.push(sqrt(num));
    }

    cout<<fixed<<setprecision(4);
    while(!root.empty()) {
        print(root.top());
        root.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll inf=1e18;

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
