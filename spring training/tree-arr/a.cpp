#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

const int maxn = 1e6 + 10;
int n,cnt;
int t[maxn * 4];
int a[maxn];

void update(int x,int d){
	for(;x <= n;x += lowbit(x)){
		t[x] += d;
	}
}

int query(int x){
	int ret = 0;
	for(;x > 0;x -= lowbit(x)){
		ret += t[x];
	}
	return ret;
}

void solve()
{
	cout << "Case " << ++cnt << ":" << endl;
	
	memset(t,0,sizeof(t));

	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		update(i,a[i]);
	}

	// cout << "Case " << ++cnt << ": " << endl;

	string op;
	int x,y,num;
	while(cin >> op){
		if(op == "End")break;
		if(op == "Add"){
			cin >> x >> num;
			update(x,num);
		}else if(op == "Sub"){
			cin >> x >> num;
			update(x,-num);
		}else if(op == "Query"){
			cin >> x >> y;
			cout << query(y) - query(x - 1) << endl;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	cnt = 0;

	while(t --){
		solve();
	}

	return 0;
}