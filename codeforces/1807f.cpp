#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int inf=1e8;


	ll t;cin >> t;
	while(t--) {
        ll n, m, i1, j1, i2, j2;
        string d;
        cin>>n>>m>>i1>>j1>>i2>>j2>>d;
        int grid[n][m];
        for (ll i=0;i<n;++i) {
            for (ll j=0;j<m;++j) {
                grid[i][j]=inf;
            }
        }
        
        --i1;--j1;
        int bounces=0;
        for (ll i=0;i<2*m*n;++i) {
            grid[i1][j1]=min(grid[i1][j1], bounces);
            bool bounced=false;
            if (d[0]=='D') {
                ++i1;
            } else {
                --i1;
            }
            if(d[1]=='R') {
                ++j1;
            } else {
                --j1;
            }
            if(i1==n) {
                d[0]='U';
                bounced=true;
                i1-=2;
            }
            if(j1==m) {
                d[1]='L';
                bounced=true;
                j1-=2;
            }
            if(i1==-1) {
                d[0]='D';
                bounced=true;
                i1+=2;
            }
            if(j1==-1) {
                d[1]='R';
                bounced=true;
                j1+=2;
            }
            if (bounced) ++bounces;
        }
        if(grid[i2-1][j2-1]==inf) grid[i2-1][j2-1]=-1;
        cout<<grid[i2-1][j2-1]<<'\n';
	}
    
    return 0;
}
