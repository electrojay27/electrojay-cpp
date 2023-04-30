#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n;

struct tiretree
{
	int next[26];
	int sum;
	int end;
	int last;
}t[maxn * 4];
int id;

void init()
{
	id = 0;
	memset(t,0,sizeof(t));
}

void Insert(string str)
{
	int p = 0;
	for(int i = 0;i < str.size();i ++)
	{
		int ch = str[i] - 'a';
		if(!t[p].next[ch])t[p].next[ch] = ++id;
		t[t[p].next[ch]].last = p;
		p = t[p].next[ch];
		t[p].sum ++;
	}
	t[p].end ++;
}

void Delete(string str,int len)//利用寻找函数寻找有多少个相同前缀的，然后减去这个相同前缀量
{
	if(len <= 0)return;
	int p = 0;
	int Last;
	for(int i = 0;i < str.size();i ++)
	{
		int ch = str[i] - 'a';
		p = t[p].next[ch];

		// if(t[p].end)t[p].end = 0;
		t[p].sum -= len;
		if(!p)return;
	}
	t[p].sum = t[p].end = 0;
	memset(t[p].next,0,sizeof(t[p].next));
}

int Search(string str)
{
	int p = 0;
	for(int i = 0;i < str.size();i ++)
	{
		int ch = str[i] - 'a';
		p = t[p].next[ch];

		// if(t[p].end && i == str.size() - 1)return true;
		// if(!t[p].sum)return false;
		if(!p)return false;
	}
	return t[p].sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n)
	{
		init();
		string op,s;
		while(n --){
			cin >> op >> s;
			if(op == "insert"){
				Insert(s);
			}else if(op == "delete"){
				Delete(s,Search(s));
			}else if(op == "search"){
				if(Search(s))cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
	}
}