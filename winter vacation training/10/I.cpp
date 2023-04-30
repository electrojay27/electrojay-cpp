#include <bits/stdc++.h>
using namespace std;
#define ld (2 * d)
#define rd (2 * d + 1)

const int maxn = 1e5 + 10;
struct node
{
	int dl,dr;
	int num;
	int lazy;//懒惰标记：-1表示无状态，0表示全变成0，1表示全变成1
	int L[2],R[2];//表示左右区间的连续1长度
	int all[2];
	int rev;//表示是否反转
}t[maxn * 4];
int a[maxn],n,m;

void pushup(int d)
{
	t[d].num = t[ld].num + t[rd].num;

	for(int i = 0;i <= 1;i ++)//01表示0和1的连续
	{
		t[d].L[i] = t[ld].L[i];
		if(!i && !t[ld].num){
			t[d].L[i] += t[rd].L[i];
		}else if(i && t[ld].num == t[ld].dr - t[ld].dl + 1){
			t[d].L[i] += t[rd].L[i];
		}

		t[d].R[i] = t[rd].R[i];
		if(!i && !t[rd].num){
			t[d].R[i] += t[ld].R[i];
		}else if(i && t[rd].num == t[rd].dr - t[rd].dl + 1){
			t[d].R[i] += t[ld].R[i];
		}

		t[d].all[i] = t[ld].R[i] + t[rd].L[i];
		t[d].all[i] = max(t[d].all[i],t[ld].all[i]);
		t[d].all[i] = max(t[d].all[i],t[rd].all[i]);
		t[d].all[i] = max(t[d].all[i],t[d].L[i]);
		t[d].all[i] = max(t[d].all[i],t[d].R[i]);
		//分别对左右最长和左右节点自身的最长对比
	}
}

void pushdown(int d)
{
	if(t[d].lazy != -1){
		t[d].rev = 0;//无效
		int x = t[d].lazy;

		t[ld].num = (t[ld].dr - t[ld].dl + 1) * x;
		t[rd].num = (t[rd].dr - t[rd].dl + 1) * x;

		t[ld].lazy = t[rd].lazy = x;
		t[ld].rev = t[rd].rev = 0;

		t[ld].L[x] = t[ld].R[x] = t[ld].all[x] = t[ld].dr - t[ld].dl + 1;
		t[ld].L[x ^ 1] = t[ld].R[x ^ 1] = t[ld].all[x ^ 1] = 0;

		t[rd].L[x] = t[rd].R[x] = t[rd].all[x] = t[rd].dr - t[rd].dl + 1;
		t[rd].L[x ^ 1] = t[rd].R[x ^ 1] = t[rd].all[x ^ 1] = 0;

		t[d].lazy = -1;
	}

	if(t[d].rev){
		t[ld].num = t[ld].dr - t[ld].dl + 1 - t[ld].num;
		t[rd].num = t[rd].dr - t[rd].dl + 1 - t[rd].num;

		if(t[ld].lazy != -1)t[ld].lazy ^= 1;//懒惰标记更新
		else t[ld].rev ^= 1;
		if(t[rd].lazy != -1)t[rd].lazy ^= 1;//懒惰标记更新
		else t[rd].rev ^= 1;

		swap(t[ld].L[0],t[ld].L[1]);
		swap(t[rd].L[0],t[rd].L[1]);

		swap(t[ld].R[0],t[ld].R[1]);
		swap(t[rd].R[0],t[rd].R[1]);

		swap(t[ld].all[0],t[ld].all[1]);
		swap(t[rd].all[0],t[rd].all[1]);

		t[d].rev = 0;
	}
}

void bulid(int d,int l,int r)
{
	t[d].dl = l;
	t[d].dr = r;
	t[d].lazy = -1;
	if(l == r){
		t[d].num = a[l];
		t[d].L[a[l]] = t[d].R[a[l]] = t[d].all[a[l]] = 1;
		return;
	}

	int mid = (l + r) / 2;
	bulid(ld,l,mid);
	bulid(rd,mid + 1,r);

	pushup(d);

	return;
}

void update(int d,int l,int r,int op)
{
	pushdown(d);

	if(l <= t[d].dl && t[d].dr <= r){
		if(op != 2){
			t[d].num = (t[d].dr -t[d].dl + 1) * op;
			t[d].lazy = op;
			t[d].L[op] = t[d].R[op] = t[d].all[op] = t[d].dr - t[d].dl + 1;
			t[d].L[op ^ 1] = t[d].R[op ^ 1] = t[d].all[op ^ 1] = 0;
		}else{
			t[d].num = t[d].dr - t[d].dl + 1 - t[d].num;
			t[d].rev = 1;
			swap(t[d].L[0],t[d].L[1]);
			swap(t[d].R[0],t[d].R[1]);
			swap(t[d].all[0],t[d].all[1]);
		}

		return;
	}

	int mid = (t[d].dl + t[d].dr) / 2;
	if(l <= mid)update(ld,l,r,op);
	if(r > mid)update(rd,l,r,op);

	pushup(d);
	return;
}

int qerry(int d,int l,int r)
{
	if(l <= t[d].dl && t[d].dr <= r)return t[d].num;
	if(t[d].dr < l || r < t[d].dl)return 0;

	pushdown(d);

	return qerry(2 * d,l,r) + qerry(2 * d + 1,l,r);
}

node len(int d,int l,int r)
{
	if(l <= t[d].dl && t[d].dr <= r)return t[d];

	pushdown(d);

	int mid = (t[d].dl + t[d].dr) / 2;
	if(r <= mid)return len(ld,l,r);
	if(l > mid)return len(rd,l,r);

	node tl = len(ld,l,r),tr = len(rd,l,r),cnt;
	cnt.num = tl.num + tr.num;

	for(int i = 0;i <= 1;i ++)
	{
		cnt.L[i] = tl.L[i];
		if(!i && !tl.num)cnt.L[i] += tr.L[i];
		else if(i && tl.num == tl.dr - tl.dl + 1)cnt.L[i] += tr.L[i];

		cnt.R[i] = tr.R[i];
		if(!i && !tr.num)cnt.R[i] += tl.R[i];
		else if(i && tr.num == tr.dr - tr.dl + 1)cnt.R[i] += tl.R[i];

		cnt.all[i] = tl.R[i] + tr.L[i];
		cnt.all[i] = max(cnt.all[i],tl.all[i]);
		cnt.all[i] = max(cnt.all[i],tr.all[i]);
		cnt.all[i] = max(cnt.all[i],cnt.L[i]);
		cnt.all[i] = max(cnt.all[i],cnt.R[i]);
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		for(int i = 1;i <= n;i ++)cin >> a[i];

		bulid(1,1,n);

		int op,x,y;
		for(int i = 1;i <= m;i ++){
			cin >> op >> x >> y;
			if(op == 1 || op == 2 || op == 0){
				update(1,x + 1,y + 1,op);
			}else if(op == 3){
				cout << qerry(1,x + 1,y + 1) << endl;
			}else{
				cout << len(1,x + 1,y + 1).all[1] << endl;
			}
		}
	}
}