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
    unordered_map<string, ll> counts;
    counts["Emperor Penguin"] = 0;
    counts["Macaroni Penguin"] = 0;
    counts["Little Penguin"] = 0;
    while(n--) {
        string cur1, cur2;
        cin>>cur1>>cur2;
        ++counts[cur1+' '+cur2];
    }
    string ans="Emperor Penguin";
    if(counts["Macaroni Penguin"] > counts[ans]) ans="Macaroni Penguin";
    if(counts["Little Penguin"] > counts[ans]) ans="Little Penguin";
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
