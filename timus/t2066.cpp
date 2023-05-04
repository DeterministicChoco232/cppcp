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
    multiset<ll> nums;
    for(ll i=0;i<3;++i) {
        ll cur;
        cin>>cur;
        nums.insert(cur);
    }
    auto it1=nums.begin();
    auto it2=next(it1);
    auto it3=next(it2);
    const ll a=*it1,b=*it2,c=*it3;
    print(min<ll>(a-b-c,a-b*c));
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
