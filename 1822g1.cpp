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
    ll n, max_a = 0;
    cin>>n;
	ll a[n];
    for(ll i=0;i<n;++i) {
        cin>>a[i];
		max_a = max<ll>(max_a, a[i]);
    }
 
	ll nums[max_a+1];
    for(ll i=1;i<=max_a;++i)
		nums[i]=0;
    for(ll i=0;i<n;++i)
		++nums[a[i]];
    ll ans=0;
    for(ll i=1;i<=max_a;++i) {
		ll cur_a = nums[i];
        if(cur_a) {
            for(ll b=2;i*b*b<=max_a;++b) {
                ans+=cur_a*nums[i*b]*nums[i*b*b];
            }
            ans+=cur_a*(cur_a-1)*(cur_a-2);
        }
    }
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
