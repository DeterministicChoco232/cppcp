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
    unordered_map<string, pair<string, bool>> db;
    ll n; cin>>n;
    while(n--) {
        string command, username, password;
        cin>>command>>username;
        if(command=="register"){
            cin>>password;
            if(db.find(username)!=db.end()) {
                print("fail: user already exists");
            } else {
                print("success: new user added");
                db.insert({username, {password, false}});
            }
        } else if(command=="login"){
            cin>>password;
            if(db.find(username)==db.end()) {
                print("fail: no such user");
            } else if(db[username].first!=password) {
                print("fail: incorrect password");
            } else if(db[username].second) {
                print("fail: already logged in");
            } else {
                print("success: user logged in");
                db[username].second=true;
            }
        } else {
            if(db.find(username)==db.end()) {
                print("fail: no such user");
            } else if(!db[username].second) {
                print("fail: already logged out");
            } else {
                print("success: user logged out");
                db[username].second=false;
            }
        }
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
