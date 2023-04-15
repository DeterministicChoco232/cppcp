#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t; cin>>t;
    ll invalid = 0;
    while(t--) {
        ll m;
        cin >> m;
        vector<vector<ll>> a;
        unordered_map<ll, pair<ll, ll>> s;
        for(ll i=0;i<m;++i) {
            a.push_back(vector<ll> ());
            ll n; cin>>n;
            for(ll j=0;j<n;++j) {
                ll temp;
                cin>>temp;
                a[i].push_back(temp);
                auto dupIndex = s.find(temp);
                if(dupIndex != s.end()) {
                    auto dupLoc = dupIndex->second;
                    a[dupLoc.first][dupLoc.second] = invalid;
                }
                s[temp] = {i, j};
            }
            
        }
        stringstream ans("");
        for (ll i=0; i<m; ++i) {
            ll valInd=-1;
            for (ll j=0; j<a[i].size(); ++j) {
                if (a[i][j] != invalid) {
                    valInd = j; break;
                }
            }
            if (valInd==-1) {
                ans.str("-1");
                break;
            }
            ans << a[i][valInd] << ' ';
        }
        cout << ans.str() << '\n';
    }
    
    return 0;
}
