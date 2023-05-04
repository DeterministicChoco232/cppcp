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
    unordered_set<ll> eigenvalues1, eigenvalues2, eigenvalues3;
    ll n;
    cin>>n;
    while(n--) {
        ll cur;
        cin>>cur;
        eigenvalues1.insert(cur);
    }
    cin>>n;
    while(n--) {
        ll cur;
        cin>>cur;
        if(eigenvalues1.find(cur)!=eigenvalues1.end()) eigenvalues2.insert(cur);
    }
    cin>>n;
    while(n--) {
        ll cur;
        cin>>cur;
        if(eigenvalues2.find(cur)!=eigenvalues2.end()) eigenvalues3.insert(cur);
    }
    print(eigenvalues3.size());
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
