#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        string sl, sr;
        cin >> sl >> sr;
        ll l=stoi(sl), r=stoi(sr);
        ll diff=r-l;
        ll n=sl.size();
        if (diff>99) {
            if(l%100>90) {
                cout<<(l/100+1)*100+90<<'\n';
            } else {
                cout<<(l/100)*100+90<<'\n';
            }
            continue;
        }
        ll maxLuckiness=-1,maxNumber=0;
        for(int i=l;i<=r;++i) {
            ll luckiness=-1, minD=1000,maxD=-1;
            string temp = to_string(i);
            for(char c : temp) {
                if (c>maxD) maxD=c;
                if (c<minD) minD=c;
            }
            if(maxD-minD>maxLuckiness) {
                maxLuckiness=maxD-minD;
                maxNumber=i;
            }
        }
        cout << maxNumber << '\n';
    }
    
    return 0;
}
