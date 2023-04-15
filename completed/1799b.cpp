#include <iostream>
#include <cmath>
#include <vector>
#define ll long long int
using namespace std;

int main() {
	int t;
	cin >> t;
    while (t--) {
        ll n; cin >> n;
        int a[n];
        int j=0;
        bool done=false;
        for (int it=0; it<n;++it) {
            cin >> a[it];
            if (a[it] == 1) done=true;
            if (a[it] != a[0]) j = it;
        }
        if (j==0) { cout << 0 << '\n'; continue; }
        if (done) { cout << -1 << '\n'; continue; }
        
        vector<int> ans; ans.reserve(n);
            
        // Make a_1 (a[0]) 2
        while (a[0]>2) {
            if (a[0] > a[j]) {
                ans.push_back(1);ans.push_back(j+1);
                a[0] = (a[0]+a[j]-1)/a[j];
            } else {
                ans.push_back(j+1);ans.push_back(1);
                a[j] = (a[j]+a[0]-1)/a[0];
            }
            if (a[0]==a[j]) { j=0;
                for (int it=1; it<n;++it) if (a[it] != a[0]) {
                    j = it; break; }
                if(j==0) { // f may be greater than 2
                    done = true;
                    cout << ans.size()/2 << '\n';
                    for (int it=0;it<ans.size();++++it) {
                        cout << ans[it] << ' ' << ans[it+1] << '\n';
                    } break; }}}
        if (done) continue;
        for (int i=1; i<n;++i) {
            int nOps = ceil(log2(a[i]));
            while(--nOps) {
                ans.push_back(i+1);ans.push_back(1); }}
        cout << ans.size()/2 << '\n';
        for (int it=0;it<ans.size();++++it) {
            cout << ans[it] << ' ' << ans[it+1] << '\n';
        }}
    return 0;
}
