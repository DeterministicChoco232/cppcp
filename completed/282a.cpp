#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x = 0;
    cin >> n;
    for (int i = 0; i<n; ++i) {
        string s;
        cin >> s;
        if (s[1] == '+') ++x;
    }
    cout << 2*x-n;
    
    return 0;
}
