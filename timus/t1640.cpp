// solve function on line 20
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void print() {
    cout<<'\n';
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    cout << t << ' ';
    print(std::forward<Args>(args)...);
}

void solve() {
    ll n;
    cin>>n;
    ll maxdist=0;
    while(n--) {
        ll a,b;
        cin>>a>>b;
        maxdist=max(maxdist,a*a+b*b);
    }
    print(0, 0, sqrt(ld(maxdist)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(12);
	ll inf=1e18;

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
