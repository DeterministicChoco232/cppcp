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
    ll a[n+1];
    a[0]=0;
    for(ll i=0;i<n;++i) {
        ll cur;
        cin>>cur;
        a[i+1]=a[i]+cur;
    }
    ll maxforce=0, ind=0;
    for(ll i=2;i<n;++i) {
        ll curforce=a[i+1]-a[i-2];
        if (curforce>maxforce) {
            maxforce=curforce;
            ind=i;
        }
    }
    print(maxforce, ind);
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
