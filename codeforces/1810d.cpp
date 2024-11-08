#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll q; cin>>q;
        ll hmin=0;
        ll hmax=1e18;
        ll a,b,n,queryType;
        while(q--) {
            cin>>queryType>>a>>b;
            ll thisMin, thisMax;
            if (queryType==1) {
                cin>>n;
                thisMax=(a-b)*(n-1)+a;
                thisMin=(a-b)*(n-2)+a+1;
                if(n==1) thisMin=1;
                if(thisMin<=hmax && thisMax>=hmin) {
                    cout<<"1 ";
                    hmin=max(hmin, thisMin);
                    hmax=min(hmax, thisMax);
                } else {
                    cout<<"0 ";
                }
            } else {
                thisMin=max<ll>(1, ceil(ld(hmin-b)/(a-b)));
                thisMax=max<ll>(1, ceil(ld(hmax-b)/(a-b)));
                if (thisMin==thisMax) {
                    cout<<thisMin<<' ';
                } else {
                    cout<<-1<<' ';
                }
            }
        }
        cout<<'\n';
	}
    
    return 0;
}
