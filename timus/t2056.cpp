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
    ll total=0;
    bool scholarship = true;
    for(ll i=0;i<n;++i) {
        ll cur;
        cin>>cur;
        if(cur==3) scholarship=false;
        total+=cur;
    }

    if(!scholarship) {
        print("None");
    } else if(total==n*5) {
        print("Named");
    } else if (total>= n*4.5) {
        print("High");
    } else {
        print("Common");
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
