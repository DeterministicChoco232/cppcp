#include <iostream>
#include <regex>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int n,p,t,v,tt=0; for(scanf("%d", &n); n--; tt+=(p+t+v)>1)scanf("%d %d %d",&p,&t,&v);
    printf("%d\n",tt);
    
    return 0;
}
