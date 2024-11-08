#include <iostream>
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
        ll a,b; cin>>a>>b;
        if(a==1) {
            cout<<"1\n"<<a<<' '<<b<<'\n';
        } else {
            cout<<"2\n"<<a-1<<' '<<a<<"\n"<<a<<' '<<b<<'\n';
        }
	}
    
    return 0;
}
