#include "helpers.h"

using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void solve() {
    ll a,b,temp;
    cin>>a>>b>>temp>>temp;
    b-=temp;
    cin>>temp;
    a-=temp;
    print(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cout<<fixed<<setprecision(4);
	ll inf=1e18;

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
