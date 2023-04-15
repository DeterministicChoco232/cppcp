#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) { 
        ll n, length=0; cin>>n;
        priority_queue<ll, vector<ll>, greater<ll>> Seq;
        for(ll i=0;i<n;++i) {
            ll temp; cin>>temp;
            Seq.push(temp);
            ++length;
            if(Seq.top()<length) {
                --length;
                Seq.pop();
            }
            cout << length << ' ';
        }
        cout<<endl;
    }
    
    return 0;
}
