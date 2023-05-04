// solve function on line 22
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll inf=1e18;

void print() {
    cout<<'\n';
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    cout << t << ' ';
    print(std::forward<Args>(args)...);
}

void solve() {
    ll n;
    string s1,s2;
    cin>>n;
    s1.reserve(2*n);
    s2.reserve(n);
    cin>>s1>>s2;
    s1.append(s1);

    ll lps[n], i=1, len=0;
    lps[0]=0;
    while(i<n) {
        if(s2[i]==s2[len]) {
            ++len;
            lps[i]=len;
            ++i;
        } else {
            if(len) {
                len=lps[len-1];
            } else {
                lps[i]=0;
                ++i;
            }
        }
    }

    ll j, shifts=-1;
    i=0, j=0;
    while(i<2*n) {
        if(s1[i]==s2[j]) {
            ++i;
            ++j;
            if(j==n) {
                shifts=n-(i-j);
                break;
            }
        } else {
            if(j) {
                j=lps[j-1];
            } else {
                ++i;
            }
        }
    }
    print(shifts%n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(6);

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
