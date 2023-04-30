#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 1e5 + 10;
int n,m;
int a[maxn];
struct node
{
	i64 num;
	int lazy;
}t[maxn];

void bulid(int d,int l,int r)
{
	t[d].lazy = 0;//初始化

	if(l == r){
		t[d].num = a[l];
		return;
	}

	int mid = (l + r) / 2;
	bulid(2 * d,l,mid);
	bulid(2 * d + 1,mid + 1,r);
	t[d].num = t[2 * d].num + t[2 * d + 1].num;
}

void pushdown(int d,int l,int r)
{
	int mid = (l + r) / 2;
	t[2 * d].num = t[2 * d].num + t[d].lazy * (mid - l + 1);
	t[2 * d + 1].num = t[2 * d + 1].num + t[d].lazy * (r - mid);
	t[2 * d].lazy += t[d].lazy;
	t[2 * d + 1].lazy += t[d].lazy;
	t[d].lazy = 0;//初始化
}

void update(int d,int l,int r,int dl,int dr,int k)
{
	if(dl <= l && r <= dr){
		t[d].num += k * (r - l + 1);
		t[d].lazy += k;
		return;
	}
	if(r < dl || dr < l)return;

	pushdown(d,l,r);

	int mid = (l + r) / 2;
	update(2 * d,l,mid,dl,dr,k);
	update(2 * d + 1,mid + 1,r,dl,dr,k);
	t[d].num = t[2 * d].num + t[2 * d + 1].num;
}

i64 qerry(int d,int l,int r,int dl,int dr)
{
	if(dl <= l && r <= dr)return t[d].num;
	if(r < dl || dr < l)return 0;

	pushdown(d,l,r);

	int mid = (l + r) / 2;

	return qerry(2 * d,l,mid,dl,dr) + qerry(2 * d + 1,mid + 1,r,dl,dr);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		for(int i = 1;i <= n;i ++)cin >> a[i];
		bulid(1,1,n);
		int op,x,y,k,D;
		while(m --){
			cin >> op;
			if(op == 1){
				cin >> x >> y >> k >> D;
				update(1,1,n,x,x,k);
				if(x + 1 <= y)update(1,1,n,x + 1,y,D);
				if(y + 1 <= n)update(1,1,n,y + 1,y + 1,-(k + (y - x) * D));
			}else{
				cin >> x;
				cout << qerry(1,1,n,x,x) << endl;
			}
		}
	}

	return 0;
}