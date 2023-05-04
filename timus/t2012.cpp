#include <bits/stdc++.h>

#define print(x) cout<<x<<'\n'
using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void solve() {
    ll f;
    cin>>f;
    print((f>=7?"YES":"NO"));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(4);
	ll inf=1e18;

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
