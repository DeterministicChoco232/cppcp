#include <iostream>
#include <set>
using namespace std;

void rearrange(int arr[], int n) {
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    auto it = s.begin();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << *it << " ";
            it++;
        }
        else {
            auto rit = s.rbegin();
            cout << *rit << " ";
            s.erase(prev(rit.base()));
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        rearrange(arr, n);
    }
    return 0;
}

