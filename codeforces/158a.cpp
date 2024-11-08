#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    vector<int> scores;
    cin >> n >> k;
    scores.reserve(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp <= 0) break;
        scores.push_back(temp);
    }

    int p = scores.size();
    if (p <= k) { cout << p; return 0; }
    while (p > k && scores[k-1] == scores[k]) ++k;
    cout << k;
    
    return 0;
}
