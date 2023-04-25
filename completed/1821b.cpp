#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n; cin>>n;
        ll a[n], b[n]; //b=a'
        for(ll i=0; i<n;++i) cin>>a[i];
        for(ll i=0; i<n;++i) cin>>b[i];
        ll l=0, r=0, longestSeq=0;
        bool modified = false;
        for(ll i=0;i<n;++i) {
            if (a[i]!=b[i]) {
                modified=true;
                l=i; r=i;
                break;
            }
        }
        if (modified) {
            while (l>0 && b[l-1]<=b[l]) --l;
            while (r<n-1 && b[r+1]>=b[r]) ++r;
        } else {
            ll templ=0;
            for(ll i=1;i<n;++i) {
                if (b[i]>=b[i-1]) {
                    if(i-templ>r-l) {
                        l=templ, r=i;
                    }
                } else {
                    templ = i;
                }
            }
        }


        cout <<l+1<<' '<<r+1<< '\n';
	}
    
    return 0;
}
