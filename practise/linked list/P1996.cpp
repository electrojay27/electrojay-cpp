#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int n,m;
struct node
{
	int next;//下个人的位置
	int id;//序号
	bool vis;//是否出列
}p[maxn];

void init()
{
	for(int i = 1;i <= n;i ++){
		p[i].id = i;
		p[i].vis = false;
		p[i].next = i + 1;//指向下一个人
		if(i == n)p[i].next = 1;//回归起点
	}
}

void solve()
{
	int sum = n;
	int to = 1;
	int last;
	while(sum --){
		int num = m;
		while(num --){
			to = p[to].next;
			if(num == 2)last = to;
			if(num == 1)break;
		}
		cout << p[to].id << " ";
		p[last].next = p[to].next;
		to = p[to].next;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		init();

		solve();
	}
	return 0;
}