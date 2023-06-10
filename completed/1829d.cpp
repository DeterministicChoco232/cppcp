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
    ld n,m;
    cin>>n>>m;
    ld rat=n/m;
    ll r=-1, l=-1;
    for(ll i=0;i<25;++i) {
        if(fmod(rat, 1)==0) {
            r=i;
            break;
        }
        rat*=2;
    }
    bool possible=false;
    if(r!=-1) {
        for(ll l=0;l<25;++l) {
            if(ld(pow(2, r))/pow(3, r) == m*pow(3,l)/n) {
                possible=true; break; }
        }
    }
    print(possible?"YES":"NO");
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
