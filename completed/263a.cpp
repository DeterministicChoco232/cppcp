#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, k = 0;
    cin >> k;
    while (k == 0) { cin >> k; ++n; }
    cout << abs(n/5 - 2) + abs(n%5 - 2);
    
    return 0;
}
