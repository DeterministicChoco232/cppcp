#include <bits/stdc++.h>

#define print(x) cout<<x<<'\n'
using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void solve() {
    ll h,l;
    cin>>h>>l;
    print(l-1<<' '<<h-1);
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
