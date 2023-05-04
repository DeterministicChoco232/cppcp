#include <bits/stdc++.h>
#define print(x) cout<<x<<'\n'
using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void solve() {
    map<ll, string> dict;
    dict.insert({1, "few"});
    dict.insert({5, "several"});
    dict.insert({10, "pack"});
    dict.insert({20, "lots"});
    dict.insert({50, "horde"});
    dict.insert({100, "throng"});
    dict.insert({250, "swarm"});
    dict.insert({500, "zounds"});
    dict.insert({1000, "legion"});

    ll n;
    cin>>n;
    print(prev(dict.upper_bound(n))->second);
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
