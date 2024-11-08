// To be replaced with "Solving from line 30" or something
// Intended for C++23

// DeterministicChoco232's C++ competitive programming environment:
// https://github.com/DeterministicChoco232/cppcp
#include <bits/stdc++.h>
#ifdef DETCHOCO_ENV
#include "headers/format_containers.hpp"
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
const ll inf=1LL<<60;

template<typename T>
void print(T x) {
	print("{}", x);
}

template<typename T>
void println(T x) {
	println("{}", x);
}

// HEADERS GO HERE
// SOLUTION STARTS HERE
#define MULTIPLE_TESTS
void solve() {
}

int main() {
	ios_base::sync_with_stdio(false); // Slight io speed increase
	// But disables sync between different io streams so I only use std::print() for output.
	cin.tie(NULL); // cout must be manually flushed
	// I don't use cout though, so it might be useless.
	cout<<fixed<<setprecision(6); // floats/doubles correct to 5sf.

#ifdef MULTIPLE_TESTS
	ll t;cin >> t;
	while(t--)
#endif
	solve();
    
	return 0;
}
