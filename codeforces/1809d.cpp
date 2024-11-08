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
        string s; cin>>s;
        ll dp[s.size()+1][2];
        ll inf=INT64_MAX;
        ll delCost =1e12+1;
        ll swapCost=1e12;
        for(ll i=0;i<=s.size();++i)
            dp[i][0]=inf, dp[i][1]=inf;
        dp[0][0]=0;
        dp[0][1]=0;
        for(ll i=0;i<s.size();++i) {
            dp[i+1][0]=dp[i][0]+delCost*(s[i]=='1'); //delete 1
            dp[i+1][1]=min(dp[i+1][1], dp[i][1]+delCost*(s[i]=='0')); //delete 0
            if (i<s.size()-1 && s[i]=='1' && s[i+1]=='0') // swap
                dp[i+2][1]=dp[i][0]+swapCost;
            dp[i+1][1]=min(dp[i+1][1],dp[i+1][0]); //switch which to delete
        }
        cout<<dp[s.size()][1]<<'\n';
	}
    
    return 0;
}
