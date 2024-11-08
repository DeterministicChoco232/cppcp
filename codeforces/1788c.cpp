#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        ll n; cin>>n;
        if(n%2==0) {cout<<"No\n";continue;}
        cout<<"Yes\n";
        ll avg=2*n+1;
        ll sum=avg-(n/2);
        for(int i=2;sum<avg;i+=2) {
            cout<<i<<' '<<sum-i<<'\n';
            ++sum;
        }
        for(int i=1;i<=n;i+=2) {
            cout<<i<<' '<<sum-i<<'\n';
            ++sum;
        }
    }
    
    return 0;
}
