#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num[30];

void init()
{	
	cin >> n;

	for(int i = 0;i < n;i ++)
	{
		num[i].push_back(i);
	}
}

void find(int a,int& p,int& h)
{
	for(p = 0;p < n;p ++){
		for(h = 0;h < num[p].size();h ++)
		{
			if(num[p][h] == a)return;
		}
	}
}

void clear(int a,int h)//a是要清理木块，h是要清理的高度
{
	for(int i = h + 1;i < num[a].size();i ++)
	{
		int b = num[a][i];
		num[b].push_back(b);
	}
	num[a].resize(h+1);
}

void move(int a,int b,int h)
{
	for(int i = h;i < num[a].size();i ++)
	{
		int x = num[a][i];
		num[b].push_back(x);
	}
	num[a].resize(h);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	string op,dre;
	int a,b;
	while(cin >> op){
		if(op == "quit")break;
		cin >> a >> dre >> b;
		int ha,hb,pa,pb;

		find(a,pa,ha);
		find(b,pb,hb);

		if(pa == pb)continue;

		if(dre == "onto")clear(pb,hb);
		if(op == "move")clear(pa,ha);
		move(pa,pb,ha);
	}
	for(int i = 0;i < n;i ++)
	{
		cout << i << ":";
		for(int j = 0;j < num[i].size();j ++)cout << " " << num[i][j];
		cout << endl;
	}
	return 0;
}