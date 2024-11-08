#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;
	cin >> t;
    while(t--) {
        ll n; cin >>n;
        ll a[n+1],b[n+1];
        a[0]=0;b[0]=0;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) cin>>b[i];
        for(int i=1;i<=n;++i){
            if(a[i]<b[i]) {
                ll temp=a[i];
                a[i]=b[i];
                b[i]=temp;
            }
        }
        if(*max_element(a, a+n+1) == a[n] && *max_element(b, b+n+1)==b[n]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
