#include <iostream>
#include <regex>
#include <cstring>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "myvector.h"
using namespace std;
vector<int> soln(vector<int> nums, int target) {
    unordered_map<int, int> ts;
    for (auto i=nums.begin();i!=nums.end();++i) {
        auto p=ts.find(*i);
        if(p==ts.end()) ts[target-*i] = i-nums.begin();
        else return {ts[*i],int(i-nums.begin())};
    }
    return {};
}
int main() {

    vector<int> nums{3,2,4,5}; int target=6;
    print(soln(nums, target));
    
    return 0;
}
