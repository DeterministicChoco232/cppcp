#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r,d; cin>>r>>d;
    ll n;cin>>n;
    ll c=0;
    while (n--) {
        ll x,y,sr;
        cin>>x>>y>>sr;
        if(x*x+y*y>=(r-d+sr)*(r-d+sr) && x*x+y*y<=(r-sr)*(r-sr)) {
            ++c;
        }
    }
    cout<<c;
    return 0;
}
