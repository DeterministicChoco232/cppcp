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
    ll m,d1,d2,m2;
    cin>>m>>d1>>d2;
    ll area=m*d1;
    m2=ceil(area/ld(d2));
    for(ll k=0;k<area/m2;++k) {
        cout<<m2<<' ';
    }
    if(area%d2) {
        cout<<area%m2<<' ';
        for(ll i=0;i<d2-area/m2-1;++i) {
            cout<<0<<' ';
        }
    }
    print();
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
