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
        ll n,k; cin>>n>>k;
        cout << (((n%2==0 || k%2==1) || n==k)?"Yes\n":"No\n");
	}
    
    return 0;
}
