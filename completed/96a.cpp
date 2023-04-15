#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    char p = -1;
    int plen = 0;
    for (char c : n) {
        if ( c == p ) {
            if (++plen >= 7) {
                cout << "YES";
                return 0;
            }
        } else {
			plen = 1; p = c;
		}
    }
    cout << "NO";
    return 0;
}
