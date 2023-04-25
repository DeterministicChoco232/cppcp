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
        string s;
        cin >> s;
        ll ans = 1;
        if (s[0]=='?') ans*=9;
        for(ll i=1;i<s.size();++i) {
            if (s[i]=='?') ans*=10;
        }
        if(s[0]=='0') ans=0;
        cout<<ans<<'\n';
	}
    
    return 0;
}
