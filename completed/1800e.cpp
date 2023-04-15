#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; scanf("%d", &t);
    while(t--) {
        int n,k;
        cin >> n >> k;
        

        string s1, s2;
        cin >> s1 >> s2;
        bool if_anagram = true;
        int cnt[26];
        for(int i=0;i<26;++i) cnt[i]=0;
        for(auto c : s1) cnt[c-'a']++;
        for(auto c : s2) cnt[c-'a']--;
        for(int i=0;i<26;++i)
            if(cnt[i]!=0)  if_anagram=false;


        if(!if_anagram) {
            cout << "NO\n";
            continue;
        }
        if(n<=2*k-1) {
            int minInd = max(0,n-k);
            int midL = min(n,k)-minInd;
            if(s1.substr(minInd, midL) !=
                    s2.substr(minInd, midL)) {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
    }
    
    return 0;
}
