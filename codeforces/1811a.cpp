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
        ll n; string d; string s;
        cin >> n >> d >> s;
        ll indexToInsert=n;
        for (ll i = n-1; i>=0; --i) {
            if(s[i]<d[0]) indexToInsert=i;
        }
        s.insert(indexToInsert, d);
        cout << s << '\n';
	}
    
    return 0;
}
