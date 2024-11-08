#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;
	cin >> t;
    while (t--) {
        ll n,x,p; cin>>n>>x>>p;
        ll mid=n/2;
        bool isShiftPossible=n%2==0&&p>n;
        ll sum=x;
        bool done=false;
        for(int i=1;i<=min<ll>(p,n);++i){
            sum=(sum+i)%n;
            if(sum==0) {
                done=true;
                cout<<"Yes\n";break;
            }
            if(sum==mid&&isShiftPossible) {
                isShiftPossible=false;
                if(i+n<=p) {
                    done=true;
                    cout<<"Yes\n";break;
                }
            }
        }
        if (!done) cout<<"No\n";
    }
    
    return 0;
}
