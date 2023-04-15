#include <iostream>
#include <unordered_map>
#include <regex>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int x=0, temp;
        while (n--) {
            cin >> temp;
            if (temp % 2 == 0) { x+=temp; } else {x -= temp;}
        }
        cout << ((x>0)?"yes\n":"no\n");
    }
    
    return 0;
}
