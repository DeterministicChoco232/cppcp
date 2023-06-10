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
    vector<ll> nums;
    nums.reserve(1000001);
    for(ll i=0;i<=1000000;++i)
        nums.push_back(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;++i) {
        ll temp;
        cin>>temp;
        ++nums[temp];
    }

    ll ans=0;
    for(ll i=0;i<=1000000;++i) {
        if(nums[i]) {
            for(ll b=2;i*b*b<=1000000;++b) {
                ans+=nums[i]*nums[i*b]*nums[i*b*b];
            }
            ans+=nums[i]*(nums[i]-1)*(nums[i]-2);
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
