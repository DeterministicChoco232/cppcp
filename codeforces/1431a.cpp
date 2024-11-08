#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
Asked ChatGPT to rewrite this in Kotlin when I found out the submissions had to be in it:
import java.util.Scanner

fun main() {
val scanner = Scanner(System.`in`)
val tn = scanner.nextInt()

repeat(tn) {
    val n = scanner.nextInt()
    val v = mutableListOf<Long>()
    repeat(n) {
	v.add(scanner.nextLong())
    }
    v.sortDescending()
    var earn: Long = 0
    for (i in v.indices) {
	earn = maxOf(earn, (i+1) * v[i])
    }
    println(earn)
}
}
*/

void populate(vector<int>& v, int size) {
    v.reserve(size);
    while (size--) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tn;
    cin >> tn;
    while(tn--) {
        vector<int> v;
        cin >> n;
        populate(v, n);
        sort(v.begin(), v.end(), greater<int>());
        int earn = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            earn = max(earn, (i+1)*v[i]);
        }
        cout << earn << '\n';
    }
    
    return 0;
}
