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
    unordered_map<string, ll> chars;
    chars["Alice"] = 0;
    chars["Ariel"] = 0;
    chars["Aurora"] = 0;
    chars["Phil"] = 0;
    chars["Peter"] = 0;
    chars["Olaf"] = 0;
    chars["Phoebus"] =0;
    chars["Ralph"] = 0;
    chars["Robin"] = 0;
    chars["Bambi"] = 1;
    chars["Belle"] = 1;
    chars["Bolt"] = 1;
    chars["Mulan"] = 1;
    chars["Mowgli"] = 1;
    chars["Mickey"] = 1;
    chars["Silver"] = 1;
    chars["Simba"] = 1;
    chars["Stitch"] = 1;
    chars["Dumbo"] = 2;
    chars["Genie"] = 2;
    chars["Jiminy"] = 2;
    chars["Kuzko"] = 2;
    chars["Kida"] = 2;
    chars["Kenai"] = 2;
    chars["Tarzan"] = 2;
    chars["Tiana"] = 2;
    chars["Winnie"] = 2;

    ll n;
    cin>>n;
    ll ans=0,prev=0;
    while(n--) {
        string next;
        cin>>next;
        ll cur=chars[next];
        ans+=abs(cur-prev);
        prev=cur;
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
