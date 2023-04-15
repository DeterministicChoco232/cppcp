#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int n;
    char p[101];
    for(scanf("%d",&n);n--;strlen(p)>10?printf("%c%d%c\n",*p,strlen(p)-2,p[strlen(p)-1]):puts(p))scanf("%s",p);
    
    return 0;
}
