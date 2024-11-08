#include <iostream>
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
        ll n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        ld mid= (ld(n)+1)/2;
        ld distance1 = max(abs(mid-x1),abs(mid-y1));
        ld distance2 = max(abs(mid-x2),abs(mid-y2));
        cout << abs(ll(distance1 - distance2)) << '\n';
	}
    
    return 0;
}
