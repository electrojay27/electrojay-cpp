#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int maxn = 1e6 + 10;
int n;
int a[maxn];

struct tiretree
{
	int next[2];
	int sum;
}t[maxn * 4];
int id;

void init()
{
	id = 0;
	memset(t,0,sizeof(t));
}

void insert(int x)
{
	int p = 0;
	for(int i = 30;i >= 0;i --){
		int to = x >> i & 1;
		if(!t[p].next[to])t[p].next[to] = ++ id;
		p = t[p].next[to];
		t[p].sum ++;
	}
}

void Delete(int x)
{
	int p = 0;
	for(int i = 30;i >= 0;i --)
	{
		int to = x >> i & 1;
		p = t[p].next[to];
		t[p].sum --;
		if(!p)return;
	}
}

int search(int x)
{
	int p = 0;
	int ret = 0;
	for(int i = 30;i >= 0;i --){
		int to = x >> i & 1;
		if(t[t[p].next[to ^ 1]].sum){//反方向存在就说明异或后为1
			ret |= (1 << i);
			to ^= 1;
		}
		p = t[p].next[to];
		if(!p)break;
	}
	return ret;
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t;
	// cin >> t;
	scanf("%d",&t);
	while(t --)
	{
		init();
		// cin >> n;
		scanf("%d",&n);
		for(int i = 0;i < n;i ++)scanf("%d",a + i),insert(a[i]);

		int ans = 0;

		for(int i = 0;i < n;i ++){
			for(int j = i + 1;j < n;j ++){
				Delete(a[i]);
				Delete(a[j]);
				ans = max(ans,search(a[i] + a[j]));
				insert(a[i]);
				insert(a[j]);
			}
		}

		// cout << ans << endl;
		printf("%d\n",ans);
	}
}