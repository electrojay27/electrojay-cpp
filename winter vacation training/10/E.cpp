#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 10;
ll n,m,p;
ll a[maxn];

ll T(int x){return 2 * x;}
ll T1(int x){return 2 * x + 1;}

struct node
{
    ll add;//加法
    ll mul;//乘法//懒惰标记
    ll num;
}t[maxn * 4];

void pushdown(int d,int l,int r){
    int mid = (l + r) / 2;

    t[T(d)].num = (t[T(d)].num * t[d].mul + t[d].add * (mid - l + 1)) % p;
    t[T1(d)].num = (t[T1(d)].num * t[d].mul + t[d].add * (r - mid)) % p;

    t[T(d)].mul = (t[T(d)].mul * t[d].mul) % p;
    t[T(d)].add = (t[T(d)].add * t[d].mul + t[d].add) % p;
    t[T1(d)].mul = (t[T1(d)].mul * t[d].mul) % p;
    t[T1(d)].add = (t[T1(d)].add * t[d].mul + t[d].add) % p;

    t[d].add = 0;
    t[d].mul = 1;
    return;
}

void bulid(int d,int l,int r){
    t[d].add = 0;
    t[d].mul = 1;

    if(l == r){
        t[d].num = a[l];
        return;
    }

    int mid = (l + r) / 2;
    bulid(T(d),l,mid);
    bulid(T1(d),mid + 1,r);
    t[d].num = (t[T(d)].num + t[T1(d)].num) % p;
}

void update_1(int d,int l,int r,int dl,int dr,int k){
    if(dl <= l && r <= dr){
        t[d].num = (t[d].num * k) % p;
        t[d].mul = (t[d].mul * k) % p;
        t[d].add = (t[d].add * k) % p;
        return;
    }
    if(dr < l || dl > r)return;
    pushdown(d,l,r);

    int mid = (l + r) / 2;
    update_1(T(d),l,mid,dl,dr,k);
    update_1(T1(d),mid + 1,r,dl,dr,k);

    t[d].num = (t[T(d)].num + t[T1(d)].num) % p;
}//乘法

void update_2(int d,int l,int r,int dl,int dr,int k){
    if(dl <= l && r <= dr){
        t[d].num = (t[d].num + (r - l + 1) * k) % p;
        t[d].add = (t[d].add + k) % p;
        return;
    }
    if(dr < l || dl > r)return;
    pushdown(d,l,r);

    int mid = (l + r) / 2;
    update_2(T(d),l,mid,dl,dr,k);
    update_2(T1(d),mid + 1,r,dl,dr,k);

    t[d].num = (t[T(d)].num + t[T1(d)].num) % p;
}//加法

ll qerry(int d,int l,int r,int dl,int dr){
    if(dl <= l && r <= dr)return t[d].num;
    if(r < dl || l > dr)return 0;

    pushdown(d,l,r);

    int mid = (l + r) / 2;
    return (qerry(T(d),l,mid,dl,dr) + qerry(T1(d),mid + 1,r,dl,dr)) % p;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> m >> p){
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
        }
        bulid(1,1,n);

        ll op,x,y,k;
        for(int i = 1;i <= m;i ++){
            cin >> op;
            if(op == 1){
                cin >> x >> y >> k;
                update_1(1,1,n,x,y,k);
            }else if(op == 2){
                cin >> x >> y >> k;
                update_2(1,1,n,x,y,k);
            }else{
                cin >> x >> y;
                cout << qerry(1,1,n,x,y) << endl;;
            }
        }
    }
}