#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

	ll t;cin >> t;
	while(t--) {
        ll n,m,a,b,c;
        cin>>n>>m;
        cout<<"? 1 1"<<endl;
        cin>>a;
        ++a;
        if(a<=n) {
            cout<<"? "<<a<<' '<<1<<endl;
            cin>>b;
            ++b;
            if(b<a) {
                cout<<"! "<<a<<' '<<b<<endl;
                continue;
            }
        }
        cout<<"? "<<1<<' '<<a<<endl;
        cin>>c;
        ++c;
        cout<<"! "<<c<<' '<<a<<endl;
	}
    
    return 0;
}
