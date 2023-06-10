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
    ll cur, count=1;
    cin>>cur;
    stringstream ans;
    while(--n) {
        ll next;
        cin>>next;
        if(cur==next) {
            ++count;
        } else {
            ans<<count<<' '<<cur<<' ';
            count=1;
            cur=next;
        }
    }
    ans<<count<<' '<<cur<<' ';
    print(ans.str());
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
