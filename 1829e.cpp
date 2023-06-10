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
    pll directions[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    vector<unordered_set<ll>> lakes;
    ll maxdepth=0;
    for(ll i=0; i<n; ++i) {
        for(ll j=0;j<m;++j) {
            cin>>a[i][j];
        }
    }
    unordered_set<ll> checked;
    for(ll i=0; i<n; ++i) {
        for(ll j=0;j<m;++j) {
            if(a[i][j] && checked.find(i*n+j)==checked.end()) {
                unordered_set<ll> newlake;
                queue<pll> toCheck;
                toCheck.push({i, j});
                while(!toCheck.empty()) {
                    auto cur = toCheck.front();
                    toCheck.pop();
                    if(checked.find(cur.first*n+cur.second)!=checked.end()) continue;
                    newlake.insert(cur.first*n+cur.second);
                    checked.insert(cur.first*n+cur.second);
                    for(auto d : directions) {
                        ll ni=cur.first+d.first, nj=cur.second+d.second;
                        if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
                        if(a[ni][nj] && checked.find(ni*n+nj)==checked.end()) {
                            toCheck.push({ni, nj});
                        }
                    }
                }
                lakes.push_back(newlake);
            }
        }
    }

    for(auto lake : lakes) {
        ll curdepth=0;
        for(auto it=lake.begin(); it!=lake.end(); ++it) {
            curdepth+=a[*it/n][*it%n];
        }
        maxdepth=max(curdepth,maxdepth);
    }


    print(maxdepth);
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
