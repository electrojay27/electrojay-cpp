#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
 
inline int read()
{
    int X=0; bool flag=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
    while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
    if(flag) return X;
    return ~(X-1);
}
 
int a[MAXN], c[MAXN<<2];
 
void build(int l,int r,int id){
    int mid = (l+r)>>1;
    if(l==r){
        c[id] = a[l];
        return ;
    }
    build(l,mid,id<<1);
    build(mid+1,r,(id<<1)|1);
    c[id] = max(c[id<<1],c[(id<<1)|1]);
}
 
void update(int l, int r,int gl,int gr,int id){
    int mid = (l+r)>>1;
    if(l==gl&&r==gr){
        c[id] = 0;
        return ;
    }
    if(!c[id])  return;
    if(mid+1<=gl){
        if(c[id])update(mid+1,r,gl,gr,(id<<1)|1);
    }
    else if(mid>=gr){
        if(c[id])update(l,mid,gl,gr,id<<1);  
    }
    else{
        if(c[id]){
            update(mid+1,r,mid+1,gr,(id<<1)|1);
            update(l,mid,gl,mid,id<<1);
        }
    }
    c[id] = max(c[id<<1],c[(id<<1)|1]);
}
 
int main(){
    int t = read();
    int n,m,l,r;
    while(t--){
        n = read(), m = read();
        for(int i = 1; i <= n;i++)   a[i] = read();
        build(1,n,1);
        while(m--){
            l = read(), r = read();
            update(1,n,l,r,1);
            printf("%d\n",c[1]);
        }
    }
}
