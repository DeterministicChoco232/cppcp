#include <iostream>
#include <string>
#include <sstream>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;cin >> t;
	while(t--) {
        string l,r;
        cin>>l>>r;
        // cout<<500-t<<'.'<<l<<' '<<r<<": ";
        ll t=l.size();
        if (l==r) { // 0
            cout<<l<<'\n';
            continue;
        }
        if(r.size()>t) { // 1
            cout<<string(t, '9')<<'\n';
            continue;
        }
        stringstream ans; // 2
        ll luckiness=10,b=0;
        char cmax='0',cmin='9';
        while(r[b]==l[b] && b<t) {
            cmax=max<char>(cmax,l[b]);
            cmin=min<char>(cmin,l[b]);
            ++b;
        }
        if(b==0) { // 2.1
            if(r[b]>l[b]+1) { // 2.1.1
                ans<<string(t, l[b]+1);
            } else { // 2.1.2
                if(string(t, l[b])>=l) { // 2.1.2.1
                    ans<<string(t, l[b]);
                } else if(string(t, r[b])<=r) {
                    ans<<string(t, r[b]);
                } else { // 2.1.2.2
                    bool optimal=true;
                    for(int i=2;i<t;++i) {
                        if (l[i]<l[1]) break;
                        if (l[i]>l[1]) optimal=false;
                    }
                    ans<<l[0]<<char(l[1]+1-optimal)<<string(t-2, max<char>(l[0], l[1]+1-optimal));
                    luckiness=l[1]-l[0]+1-optimal;

                    optimal=true;
                    for(int i=2;i<t;++i) {
                        if (r[i]>r[1]) break;
                        if (r[i]<r[1]) optimal=false;
                    }
                    if(r[0]-r[1]+1-optimal < luckiness) {
                        ans.str("");
                        ans.clear();
                        ans<<r[0]<<char(r[1]+optimal-1)<<string(t-2, min<char>(r[0], r[1]+optimal-1));
                    }
                }
            }
        } else { // 2.2
            // stage 2
            char bounded;
            for (char xb=l[b]+1; xb<r[b];++xb) {
                if (max(cmax,xb)-min(xb,cmin)<luckiness) {
                    bounded=xb;
                    luckiness=max(cmax,xb)-min(xb,cmin);
                }
            }
            if (r[b]>l[b]+1) {
                for (ll i=0;i<b;++i) ans<<l[i];
                ans<<bounded;
                for (ll i=b+1;i<t;++i) ans<<cmin;
            }
            
            stringstream free;
            if(b+1<t) {
                // stage 1
                char xb=l[b];
                if(l[b+1] < max(cmax, xb)) { // 2.2.1
                    if (max(cmax,xb)-min(xb,cmin)<luckiness) {
                        ans.str(""); ans.clear();
                        for (ll i=0;i<=b;++i) ans<<l[i];
                        for (ll i=b+1;i<t;++i) ans<<max(cmax,xb);
                        luckiness=max(cmax,xb)-min(cmin,xb);
                    }
                } else { // 2.2.2
                    bool optimal=true;
                    for(int i=b+2;i<t;++i) {
                        if (l[i]<l[b+1]) break;
                        if (l[i]>l[b+1]) optimal=false;
                    }
                    if(l[b+1]+1-optimal-min(cmin,xb)<luckiness) {
                        ans.str(""); ans.clear();
                        luckiness=1-optimal+l[b+1]-min(cmin,xb);
                        for (ll i=0;i<=b;++i) ans<<l[i];
                        ans<<char(l[b+1]+1-optimal)<<string(t-b-2, max<char>(cmax, l[b+1]+1-optimal));
                    }
                }
                // stage 3
                xb=r[b];
                if(r[b+1] > min(cmin, xb)) { // 2.2.1
                    if (max(cmax,xb)-min(xb,cmin)<luckiness) {
                        ans.str(""); ans.clear();
                        for (ll i=0;i<=b;++i) ans<<r[i];
                        for (ll i=b+1;i<t;++i) ans<<min(cmin, xb);
                        luckiness=max(cmax,xb)-min(cmin,xb);
                    }
                } else { // 2.2.2
                    bool optimal=true;
                    for(int i=b+2;i<t;++i) {
                        if (r[i]>r[b+1]) break;
                        if (r[i]<r[b+1]) optimal=false;
                    }
                    if(max(cmax,xb)-r[b+1]+1-optimal<luckiness) {
                        ans.str(""); ans.clear();
                        luckiness=max(cmax,xb)-r[b+1]+1-optimal;
                        for (ll i=0;i<=b;++i) ans<<r[i];
                        ans<<char(r[b+1]-1+optimal)<<string(t-b-2, min<char>(xb, r[b+1]-1+optimal));
                    }
                }
            } else {
                char xb=l[b];
                if(max(cmax,xb)-min(cmin, xb)<luckiness) {
                     ans.clear();ans.str(l);
                     luckiness=max(cmax,xb)-min(cmin,xb);
                }
                xb=r[b];
                if(max(cmax,xb)-min(cmin, xb)<luckiness) {
                     ans.clear();ans.str(r);
                     luckiness=max(cmax,xb)-min(cmin,xb);
                }
            }
        }

        cout<<ans.str()<<'\n';
	}
    
    return 0;
}
