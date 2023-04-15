#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void populate(vector<long long>& v, long long size) {
    v.reserve(size);
    while (size--) {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    vector<long long> v;
    populate(v, n);

    unordered_map<long long, long long> index_map;
    for (long long i = 0; i < n; ++i) {
        index_map[v[i]] = i;
    }

    long long sum = 0;
    long long prev_index = index_map[1];
    for (long long i = 2; i <= n; ++i) {
        long long index = index_map[i];
        sum += abs(index - prev_index);
        prev_index = index;
    }
    cout << sum;

    return 0;
}

