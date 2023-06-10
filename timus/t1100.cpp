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
    vector<ll> sorted[101];
    for(ll i=0;i<101;++i)
        sorted[i]={};
    while(n--) {
        ll id, s;
        cin>>id>>s;
        sorted[s].push_back(id);
    }
    for(ll i=100;i>=0;--i) {
        for(ll j=0; j<sorted[i].size(); ++j) {
            print(sorted[i][j], i);
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
