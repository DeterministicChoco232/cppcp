#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    for(int i=0;i<a.size();++i) {
        if(a[i]>='a') a[i]+='A'-'a';
        if(b[i]>='a') b[i]+='A'-'a';
    }
    cout << ((a==b)?0:(a<b)?-1:1);    
    return 0;
}
