// solve function on line 20
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;

void print() {
    cout<<'\n';
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    cout << t << ' ';
    print(std::forward<Args>(args)...);
}

void solve() {
    ld l,h,av, g=9.81;
    cin>>l>>h>>av;
    l/=100;
    h/=100;
    av/=60;
    ld t=sqrt(max<ld>(0,2*(h-l/2)/g));
    ld finalrev=t*av;
    finalrev-=floor(finalrev);
    if(finalrev<.25 || finalrev>.75) {
        print("butter");
    } else {
        print("bread");
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(4);
	ll inf=1e18;

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
