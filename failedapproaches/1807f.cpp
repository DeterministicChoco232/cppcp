#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;


tuple<ll, ll, ll, ll, ll> extendedEuclid(ll a, ll b) {
    ll t0=1,t1=0,s0=0,s1=1;
    while(b) {
        ll q=a/b;
        t0-=q*t1;
        s0-=q*s1;
        a-=q*b;
        swap(t0,t1);
        swap(s0,s1);
        swap(a,b);
    }
    ll gcd=__gcd(t1,s1);
    t1/=gcd;
    s1/=gcd;
    return {a, t0, s0, t1 ,s1};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll inf=1e18;

	ll t;cin >> t;
	while(t--) {
        ll n,m,i1,i2,j1,j2;
        string d;
        cin>>n>>m>>i1>>j1>>i2>>j2>>d;
        // Flipping grid so that ball always goes DR
        if(d[0]=='U') {
            i1=n+1-i1;
            i2=n+1-i2;
        }
        if(d[1]=='L') {
            j1=m+1-j1;
            j2=m+1-j2;
        }

        ll min_bounces = inf;
        pair<ll, ll> reflections[2][2];

        // Bounces which aren't obtainable by shifting r by (2n-2)*t or c by (2m-2)*s 
        reflections[0][0] = {i2, j2};
        reflections[0][1] = {i2, 2*m-j2};
        reflections[1][0] = {2*n-i2, j2};
        reflections[1][1] = {2*n-i2, 2*m-j2};


        auto eed = extendedEuclid(2*n-2, 2*m-2);
        // find gs and gt for gcd(2n-2,2m-2)=gt(2m-2)-gs(2n-2)
        ll gcd=get<0>(eed), gs=-get<1>(eed), gt=get<2>(eed), zs=-get<3>(eed), zt=get<4>(eed);
        zs = abs(zs), zt=abs(zt);
        for(ll i=0;i<2;++i) {
            for(ll j=0;j<2;++j) {
                // equation of ball travel: r=c+k
                // for r=i1, i1=j1+k => k=i1-j1
                // when c=j2, r=j2+i1-j1
                // difference from row of target, b=i2-(j2+i1-j1)=i2-i1+j1-j2
                ll b=reflections[i][j].first-i1+j1-reflections[i][j].second;
                // b=(b%(2*n-2)+2*n-2)%(2*n-2);
                // possible targets (r,c) = (i2+s(2n-2), j2+t(2m-2)
                // intersection with ball, i2+s(2n-2) = j2+t(2m-2) + i1-j1
                // b = t(2m-2) - s(2n-2)
                // solve linear Diophantine equation for any s and t
                // b/gcd * gcd = b/gcd * (gt(2m-2)-gs(2n-2)
                // b = (b*gt/gcd)(2m-2) - (b*gt/gcd)(2n-2)
                if(b%gcd!=0) continue;
                // so t=b*gt/gcd, s=b*gs/gcd
                ll t=b*gt/gcd, s=b*gs/gcd;
                // add or subtract 0=zs(2m-2) - zt(2n-2) to find best solution
                while(t>0 || s>0) {
                    t-=zt;
                    s-=zs;
                }
                while(t<0 || s<0) {
                    t+=zt;
                    s+=zs;
                }
                if(i1>i2 && t==0 && s==0) {
                    t+=zt;
                    s+=zs;
                }

                ll bounces=i+j+2*t+2*s;
                min_bounces=min(min_bounces, bounces);
            }
        }


        if(min_bounces==inf) {
            cout<<"-1\n";
        } else {
            cout<<min_bounces<<"\n";
        }
	} 
    
    return 0;
}
