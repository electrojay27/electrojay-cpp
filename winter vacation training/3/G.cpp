#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while(scanf("%d",&n)!=EOF){
        priority_queue<int,vector<int>,greater<int> >all;
        int a;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            all.push(a);
        }
        int sum = 0;
        int cnt = 0;
        int flag = 0;
        while(!all.empty()){
            sum += all.top();
            all.pop();
            flag ++;
            if(flag == 2){
                flag = 0;
                cnt += sum;
                all.push(sum);
                sum = 0;
            }
        }printf("%d\n",cnt);
    }
}