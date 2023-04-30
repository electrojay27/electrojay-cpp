#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
struct tiretree
{
	int next[2];
	int sum;
}t[maxn * 4];
int id,n;

void init()
{
	id = 0;
	memset(t,0,sizeof(t));
}

void Insert(int x)
{
	int p = 0;
	for(int i = 27;i >= 0;i --)
	{
		int to = x >> i & 1;
		// cout << to;
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
		t[p].sum ++;
	}
	// cout << endl;
}

void Delete(int x)
{
	int p = 0;
	for(int i = 27;i >= 0;i --)
	{
		int to = x >> i & 1;
		// cout << to;
		p = t[p].next[to];
		if(!p)return;
		t[p].sum --;
	}
	// cout << endl;
}

int Search(int x,int lim)
{
	int p = 0;
	int ret = 0;
	int ans = 0;
	for(int i = 27;i >= 0;i --)
	{
		int to = x >> i & 1;
		int noto = to ^ 1;
		if(t[p].next[noto] && t[t[p].next[noto]].sum && (ret|(1 << i)) < lim){
			ans += t[t[p].next[to]].sum;
			ret |= (1 << i);
			// cout << i << " " << ret << endl;
			to = noto;
		}
		// cout << to;
		p = t[p].next[to];
		if(!p)break;
	}
	// cout << endl;
	ans += t[p].sum;
	return ans;
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	while(scanf("%d",&n)!=EOF)
	{
		init();
		while(n --){
			int op,pi,li;
			scanf("%d",&op);
			if(op == 1){
				scanf("%d",&pi);
				Insert(pi);
			}else if(op == 2){
				scanf("%d",&pi);
				Delete(pi);
			}else if(op == 3){
				scanf("%d%d",&pi,&li);
				printf("%d\n",Search(pi,li));
			}
		}
	}
	return 0;
}