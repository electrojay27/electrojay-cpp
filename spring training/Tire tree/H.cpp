#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 1e6 + 10;
int n;
int cnt,ans,id;
int d[maxn];
struct node
{
	int e;
	int w;
	int ne;
}edge[maxn];
int head[maxn];
struct tire
{
	int next[2];
	int end;
}t[maxn];

void init()
{
	id = ans = cnt = 0;
	memset(t,0,sizeof(t));
	memset(head,0,sizeof(head));
	memset(edge,0,sizeof(edge));
	memset(d,0,sizeof(d));
}

void add(int a,int b,int c)
{
	edge[++cnt].e = b;//结束点
	edge[cnt].w = c;//路径长度
	edge[cnt].ne = head[a];//指向上一条路
	head[a] = cnt;//指向下一条
}

void insert(int x)
{
	int p = 0;
	for(int i = 31;i >= 0;i --)
	{
		int to = (x >> i & 1);
		if(!t[p].next[to])t[p].next[to] = ++ id;
		p = t[p].next[to];
	}
}

int search(int x)
{
	int sum = 0,p = 0;
	for(int i = 31;i >= 0;i --)
	{
		int to = (x >> i & 1);
		int noto = (to ^ 1);
		if(t[p].next[noto])p = t[p].next[noto],sum = (sum << 1 | 1);
		else p = t[p].next[to],sum <<= 1;
	}
	return sum;
}

void dfs(int b,int fa)
{
	for(int i = head[b];i;i = edge[i].ne){
		int to = edge[i].e;
		if(to != fa){
			d[to] = (d[b] ^ edge[i].w);
			dfs(to,b);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n)
	{
		init();
		int a,b,c;
		for(int i = 1;i < n;i ++)
		{
			cin >> a >> b >> c;
			add(a,b,c);
			add(b,a,c);
		}

		dfs(1,-1);

		for(int i = 0;i < n;i ++)insert(d[i]);

		for(int i = 0;i < n;i ++)
		{
			ans = max(ans,search(d[i]));
			// insert(d[i]);
		}

		cout << ans << endl;
	}
	return 0;
}