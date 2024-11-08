#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll nums[3];
    nums[0]=0;
    nums[1]=0;
    nums[2]=0;
    string temp;cin>>temp;
    for(ll i=0; i<temp.size(); i+=2) {
        ++nums[temp[i]-'1'];
    }
    if(nums[0]!=0) {
        cout<<1;--nums[0];
    } else if (nums[1]!=0) {
        cout<<2;--nums[1];
    } else {
        cout<<3;--nums[2];
    }
    for(int n=0;n<3;++n) {
        for(ll i=0;i<nums[n];++i) {
            cout<<'+'<<n+1;
        }
    }
    
    return 0;
}
