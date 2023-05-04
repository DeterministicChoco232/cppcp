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
    pll movements[8] = {
        pll(1, 2),
        pll(-1, 2),
        pll(1, -2),
        pll(-1, -2),
        pll(2, 1),
        pll(-2, 1),
        pll(2, -1),
        pll(-2, -1),
    };
    string s;
    cin>>s;
    char r=s[0],c=s[1];
    ll possibities=0;

    for(ll i=0;i<8;++i) {
        bool valid=true;
        ll newr = char(r+movements[i].first);
        ll newc = char(c+movements[i].second);
        if(newr>='a'&&newr<='h'&&newc>='1'&&newc<='8') ++possibities;
    }
    print(possibities);
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
