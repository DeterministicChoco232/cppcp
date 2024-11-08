#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
    while(t--) {
        int n; cin >> n;
        int sum=n-1;
        string s;
        cin >> s;
        for(int i = 0; i < n-2; ++i) {
            if (s[i]==s[i+2]) sum--;
        }
        cout << sum << '\n';
    }
    
    return 0;
}
