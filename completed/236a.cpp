#include <iostream>
#include <set>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s;
    set<char> chars;
    ll distinct=0;
    for(char c:s) {
        if(chars.find(c)==chars.end()) distinct++;
        chars.insert(c);
    }
    cout<<((distinct%2==0)?"CHAT WITH HER!":"IGNORE HIM!");
    
    return 0;
}
