#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n,m;
struct node
{
	int dl,dr,numl,numr;
}t[4 * maxn];

void bulid(int d,int l,int r)
{
	t[d].dl = l;
	t[d].dr = r;
	t[d].numl = t[d].numr = 0;
	if(l == r)return;

	int mid = (l + r) / 2;
	bulid(2 * d,l,mid);
	bulid(2 * d + 1,mid + 1,r);
}

void update_1(int d,int to)
{
	if(t[d].dl == t[d].dr){
		t[d].numl ++;
		return;
	}

	if(to > t[2 * d].dr)update_1(2 * d + 1,to);
	else update_1(2 * d,to);

	t[d].numl = t[2 * d].numl + t[2 * d + 1].numl;
	return;
}

void update_2(int d,int to)
{
	if(t[d].dl == t[d].dr){
		t[d].numr ++;
		return;
	}

	if(to > t[2 * d].dr)update_2(2 * d + 1,to);
	else update_2(2 * d,to);

	t[d].numr = t[2 * d].numr + t[2 * d + 1].numr;
	return;
}

int qerry_1(int d,int l,int r)
{
	if(l <= t[d].dl && t[d].dr <= r)return t[d].numl;
	if(t[d].dr < l || r < t[d].dl)return 0;

	return qerry_1(2 * d,l,r) + qerry_1(2 * d + 1,l,r); 
}

int qerry_2(int d,int l,int r)
{
	if(l <= t[d].dl && t[d].dr <= r)return t[d].numr;
	if(t[d].dr < l || r < t[d].dl)return 0;

	return qerry_2(2 * d,l,r) + qerry_2(2 * d + 1,l,r); 
}

void solve()
{
	int op,x,y;
	bulid(1,1,n);
	for(int i = 1;i <= m;i ++){
		cin >> op >> x >> y;
		if(op == 1){
			update_1(1,x);
			update_2(1,y);
		}else{
			cout << qerry_1(1,1,y) - qerry_2(1,1,x - 1) << endl;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m)
	{
		solve();
	}
	return 0;
}