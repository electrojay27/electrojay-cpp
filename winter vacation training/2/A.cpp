#include <bits/stdc++.h>
using namespace std;
void hanoi(int n,char A,char B,char C){
    if(n==1)printf("%d:%c->%c\n",n,A,C);
    else{
        hanoi(n-1,A,C,B);
        printf("%d:%c->%c\n",n,A,C);
        hanoi(n-1,B,A,C);
    }
}
int main()
{
    int A,B,C,n;
    scanf("%d %c %c %c",&n,&A,&B,&C);
    hanoi(n,A,B,C);
    return 0;
}