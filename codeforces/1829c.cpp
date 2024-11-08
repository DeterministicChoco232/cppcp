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

#define TEST_CASES
void solve() {
    ll n;
    cin>>n;
    ll book1=inf, book2=inf, both=inf;
    for(ll i=0; i<n; ++i) {
        ll curbook, m;
        cin>>m>>curbook;
        if(curbook==01) book2=min(book2, m);
        if(curbook==10) book1=min(book1, m);
        if(curbook==11) both=min(both, m);
    }
    ll ans=inf;
    if(book1<inf && book2 < inf) ans=book1+book2;
    if(both<inf) ans=min(ans,both);
    if(ans==inf)ans=-1;
    print(ans);
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
