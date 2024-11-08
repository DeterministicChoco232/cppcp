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
        ll minimum1 = 4, minimum2 = 4;
        ll n,m, x1, x2, y1, y2;
        cin>>n>>m>>x1>>y1>>x2>>y2;

        if(x1==1 || x1==n) minimum1--;
        if(x2==1 || x2==n) minimum2--;
        if(y1==1 || y1==m) minimum1--;
        if(y2==1 || y2==m) minimum2--;
        cout<<min(minimum1, minimum2)<<'\n';
	}
    
    return 0;
}
