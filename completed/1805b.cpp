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
        ll n; cin>>n;
        string s; cin>>s;
        char minChar='z'; ll minCharIndex=0;
        for(ll i=0;i<n;++i) {
            if(s[i]<=minChar) {
                minChar = s[i];
                minCharIndex=i;
            }
        }
        for(ll i=minCharIndex; i>0; --i) {
            ll temp=s[i];
            s[i]=s[i-1];
            s[i-1]=temp;
        }
        cout<<s<<'\n';
	}
    
    return 0;
}
