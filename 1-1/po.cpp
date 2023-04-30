#include <bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
    while(scanf("%d",&n)!=EOF){
        stack<int> s;
        int cnt = 0;//记录次数
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            while(!s.empty()&&s.top()>x){
                s.pop();//当栈顶元素超过目前的高度时就把栈顶删除，寻找小的数
            }//保持单调栈，从小到大
            if(!s.empty()&&s.top()==x)continue;//当相等时直接跳过，将二者合成一个
            if(x)cnt++,s.push(x);
        }printf("%d\n",cnt);
    }
}