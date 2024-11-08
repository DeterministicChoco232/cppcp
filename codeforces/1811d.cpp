#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

bool isValid(ll fibonacci[46], ll n,ll x,ll y) {
    if(n==0) return true;
    if(y>fibonacci[n]) {
        return isValid(fibonacci, n-1, y-fibonacci[n], x);
    } else if(y<=fibonacci[n-1]) {
        return isValid(fibonacci, n-1, y, x);
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	ll fibonacci[46];
    fibonacci[0]=1; fibonacci[1]=1;
    for (ll i=2; i<46;++i) {
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
    }
    while(t--) {
        ll n, x, y; cin>>n>>x>>y;
        cout<<((isValid(fibonacci, n, x, y))?"Yes\n":"No\n");
	}
    
    return 0;
}
