#include <bits/stdc++.h>
using namespace std;
#define ld (2 * d)
#define rd (2 * d + 1)

const int maxn = 1e5 + 10;
int n,m,op;
int a[maxn];
int last,x,y;
int ans;
int need[maxn];
struct node
{
	vector<int> all;
	int num;
}t[maxn * 4];

void bulid(int d,int l,int r)
{
	if(l == r)
	{
		t[d].num = a[l];
		return;
	}

	int mid = (l + r) / 2;
	bulid(ld,l,mid);
	bulid(rd,mid + 1,r);

	t[d].num = t[ld].num + t[rd].num;//上传气球数量
}

void insert(int d,int l,int r,int dl,int dr,int id)
{
	if(dl == l && dr == r){
		//如果完全相等
		need[id] ++;
		t[d].all.push_back(id);//插入这个节点的队列中
		return;
	}

	int mid = (l + r) / 2;
	if(mid >= dr)insert(ld,l,mid,dl,dr,id);
	else if(mid < dl)insert(rd,mid + 1,r,dl,dr,id);
	else insert(ld,l,mid,dl,mid,id),insert(rd,mid + 1,r,mid + 1,dr,id);
}

void protect(int d)
{
	for(auto it : t[d].all){
		need[it] --;
		if(!need[it])ans ++;//所需要的区间全部清空，ans加一
	}
}

void update(int d,int l,int r,int dl,int dr)
{
	t[d].num --;//在此区间内气球数量减一
	if(!t[d].num)protect(d);
	if(l == r)return;

	int mid = (l + r) / 2;
	if(mid >= dl)update(ld,l,mid,dl,dr);
	else update(rd,mid + 1,r,dl,dr);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		for(int i = 1;i <= n;i ++)cin >> a[i],need[i] = 0;//初始化

		bulid(1,1,n);

		for(int i = 1;i <= m;i ++)
		{
			cin >> x >> y;
			insert(1,1,n,x,y,i);
		}

		cin >> op;
		last = 0;
		ans = 0;
		for(int i = 1;i <= op;i ++)
		{
			cin >> x;
			x = (x + last - 1) % n + 1;
			update(1,1,n,x,x);
			last = ans;
			cout << last << endl;
		}
	}
}