#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n,m,x,op;
struct node
{
	int last;//上个人
	int next;//下个人
	int id;//序号
	bool vis;//是否出列
}p[maxn];

void init()
{
	for(int i = 1;i <= n;i ++){
		p[i].id = i;
		p[i].vis = false;
		p[i].next = 0;//指向下一个人
		p[i].last = 0;
	}
	p[1].vis = true;
	p[0].next = 1;
	p[1].last = 0;//初始化
}

void solve()
{
	for(int i = 2;i <= n;i ++){
		cin >> x >> op;
		if(op){
			p[i].last = x;
			p[i].next = p[x].next;
			p[p[x].next].last = i;
			p[x].next = i;
		}else{
			p[i].next = x;
			p[i].last = p[x].last;
			p[p[x].last].next = i;
			p[x].last = i;
		}
		p[i].vis = true;//入列
	}

	int to = 0;

	// while(p[to].next){
	// 	cout << p[to].next << " ";
	// 	to = p[to].next;
	// }
	// cout << endl;

	cin >> m;
	while(m --){
		cin >> x;
		if(p[x].vis){
			p[p[x].last].next = p[x].next;
			p[p[x].next].last = p[x].last;
			p[x].last = 0;
			p[x].next = 0;
		}
		p[x].vis = false;
	}

	to = 0;
	while(p[to].next){
		if(p[p[to].next].vis)cout << p[to].next << " ";
		to = p[to].next;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n){
		init();
		solve();
	}
	return 0;
}