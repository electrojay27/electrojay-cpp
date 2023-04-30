#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int n;
int a[maxn];

struct node
{
	int next[2];
	int sum;
}t[maxn * 4];
int id;

void init()
{
	id = 0;
	memset(t,0,sizeof(t));
	a[0] = 0;
}

void insert(int x)
{
	int p = 0;
	for(int i = 31;i >= 0;i --)
	{
		int to = (x >> i) & 1;
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
		t[p].sum ++;
	}
}

int Max_xor(int x)
{
	int ret = 0;
	int p = 0;
	for(int i = 31;i >= 0;i --)
	{
		int to = ((x >> i) & 1) ^ 1;
		// cout << to;
		if(t[p].next[to]){
			ret |= (1 << i);
		}else{
			to ^= 1;
		}
		p = t[p].next[to];
		// cout << ans << endl;
	}
	// cout << endl;
	return ret;
}

int Min_xor(int x)
{
	int p = 0;
	int ret = 0;
	for(int i = 31;i >= 0;i --)
	{
		int to = (x >> i) & 1;
		if(!t[p].next[to] || t[p].next[to ^ 1] && t[t[p].next[to]].sum < 2){
			to ^= 1;
			ret |= (1 << i);
		}
		p = t[p].next[to];
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	for(int cnt = 1;cnt <= T;cnt ++){
		init();

		cin >> n;

		int mx = 0,mn = (1 << 31) - 1;
		for(int i = 1;i <= n;i ++)cin >> a[i],a[i] ^= a[i - 1];

		for(int i = 0;i <= n;i ++)insert(a[i]);

		for(int i = 0;i <= n;i ++)
		{
			mn = min(mn,Min_xor(a[i]));
			mx = max(mx,Max_xor(a[i]));
		}

		cout << "Case " <<  cnt << ": " << mx << " " << mn << endl;
	}
}