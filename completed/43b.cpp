#include <iostream>
#include <string>
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    ll letters['z'-'A'+1] = {0};
    for( char c:s1 ) if(c!=' ')letters[c-'A']++;
    for( char c:s2 ) if(c!=' ')letters[c-'A']--;
    bool possible=true;
    for(ll letter : letters) {
        if (letter<0) possible=false;
    }
    cout<<(possible?"YES\n":"NO\n");
    
    return 0;
}
