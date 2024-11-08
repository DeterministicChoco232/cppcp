#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n; cin>>n;
        ll prevNum=(n+1)/2, nextNum=(n+2)/2;
        ll p[n], l,r;
        for(ll i=0;i<n;++i) {
            cin >> p[i];
            if(p[i]==prevNum) l=i;
            if(p[i]==nextNum) r=i;
        }
        ll ans=(n+1)/2;
        if(l>r) {cout<<ans<<'\n'; continue;}
        --ans; ++nextNum; --prevNum;
        while (++r<n) {
            if(p[r]==nextNum) {
                while (--l>=0) {
                    if(p[l]==prevNum) break;
                }
                if(l<0) break;
                ++nextNum; --prevNum; --ans;
            }
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
