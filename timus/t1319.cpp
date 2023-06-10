// solve function on line 22
#include <bits/stdc++.h>

using ll = long long;
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
    ll n;
    cin>>n;
    ll ans[n][n];
    ll cur = 1, i=0, j=n-1;
    while(cur<=n*n) {
        if(i>=0 && j>=0 && i<n && j<n) {
            ans[i][j]=cur;
            ++cur;
        }
        ++i;
        ++j;
        if(j>=n) {
            i=i-j+1;
            j=0;
        }
    }

    for(ll i=0; i<n;++i) {
        for(ll j=0; j<n;++j)
            cout<<ans[i][j]<<' ';
        print();
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
