#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

struct Comparehorw {
    const vector<ll>& a;
    bool operator()(ll i1, ll i2) const {
        return a[i1] < a[i2] || (a[i1] == a[i2] && i1 < i2);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll inf=1e18;

	ll t;cin >> t;
	while(t--) {
        ll n;
        cin>>n;
        vector<ll> a,b;a.reserve(n);b.reserve(n);
        ll maxh=0, maxw=0, total=0;
        for(ll i=0;i<n;++i) {
            ll temp1, temp2;
            cin>>temp1>>temp2;
            a.push_back(temp1);
            b.push_back(temp2);
            if(a[i]>maxh)maxh=a[i];
            if(b[i]>maxw)maxw=b[i];
            total+=a[i]*b[i];
        }
        bool maxhvalid=(total%maxh)==0, maxwvalid=(total%maxw)==0 && n>1;

        
        if (maxhvalid && maxwvalid) {
            multiset<ll, Comparehorw> sortedh{Comparehorw{a}}, sortedw{Comparehorw{b}};
            bool checked[n];
            for(ll i=0;i<n;++i) {
                sortedh.insert(i);
                sortedw.insert(i);
                checked[i]=false;
            }

            ll curh=maxh, curw=total/maxh;
            auto hit=sortedh.rbegin();
            auto wit=sortedw.rbegin();
            while(hit!=sortedh.rend() && curh==a[*hit]) {
                while(hit!=sortedh.rend() && curh==a[*hit]) {
                    if(!checked[*hit]) {
                        curw-=b[*hit];
                    }
                    checked[*hit]=true;
                    ++hit;
                }
                while(wit!=sortedw.rend() && checked[*wit]){
                    ++wit;
                }
                while(wit!=sortedw.rend() && curw==b[*wit]) {
                    if(!checked[*wit]) {
                        curh-=a[*wit];
                    }
                    checked[*wit]=true;
                    ++wit;
                }
                while(hit!=sortedh.rend() && checked[*hit]){
                    ++hit;
                }
            }
            maxhvalid=curh==0 || curw==0;
            for(ll i=0;i<n;++i) {
                checked[i]=false;
            }

            curh=total/maxw, curw=maxw;
            hit=sortedh.rbegin();
            wit=sortedw.rbegin();
            while(wit!=sortedw.rend() && curw==b[*wit]) {
                while(wit!=sortedw.rend() && curw==b[*wit]) {
                    if(!checked[*wit]) {
                        curh-=a[*wit];
                    }
                    checked[*wit]=true;
                    ++wit;
                }
                while(hit!=sortedh.rend() && checked[*hit]){
                    ++hit;
                }
                while(hit!=sortedh.rend() && curh==a[*hit]) {
                    if(!checked[*hit]) {
                        curw-=b[*hit];
                    }
                    checked[*hit]=true;
                    ++hit;
                }
                while(wit!=sortedw.rend() && checked[*wit]){
                    ++wit;
                }
            }
            maxwvalid=curh==0 || curw==0;
        }

        cout<<ll(maxhvalid+maxwvalid)<<'\n';
        if(maxhvalid) cout<<maxh<<' '<<total/maxh<<'\n';
        if(maxwvalid) cout<<total/maxw<<' '<<maxw<<'\n';
	}
    
    return 0;
}
