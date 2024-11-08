#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void replaceChar(std::string& str, char oldChar, char newChar) {
    for (char& c : str) {
        if (c == oldChar) {
            c = newChar;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        bool fail = false;
        for (auto i = s.begin(); i < s.end(); ++i) {
            int index = i - s.begin();
            if (*i == 0 || *i == 1) {
                if (*i != index % 2 ) {
                    std::cout << "NO\n";
                    fail = true;
                    break;
                }

            } else {
                replaceChar(s, *i, char(index % 2));
            }
        }
        if (not fail) cout << "YES\n";
    }
    
    return 0;
}
