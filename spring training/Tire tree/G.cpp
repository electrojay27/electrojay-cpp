#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int n,m;
string text;
string op;
string word[maxn];
vector<int> ans;

struct tire
{
	int next[26];
	int end;
}t[maxn];
int id;

void Insert(string str,int idx)
{
	int p = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		if(!t[p].next[to])t[p].next[to] = ++ id;
		p = t[p].next[to];
	}
	if(!t[p].end)t[p].end = idx;
}

int Search(string str){
	int p = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		p = t[p].next[to];
		if(!p)return 0;
	}
	return t[p].end;//放回序号
}

bool dfs(int x){
	// vector<int> ans;
	if(x == n){
		for(int i = 0;i < ans.size();i ++){
			cout << word[ans[i]] << " ";
		}
		cout << endl;
		return true;
	}else{
		int p = 0;
		for(int i = x;i < text.size();i ++){
			int to = text[i] - 'a';
			p = t[p].next[to];
			
			if(!p)break;
			
			if(t[p].end){
				ans.push_back(t[p].end);
				if(dfs(i + 1))return true;
				ans.pop_back();
			}
		}
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while(cin >> n){
		// vector<string> word;
		id = 0;
		memset(t,0,sizeof(t));

		cin >> text;
		// reverse(text.begin(),text.end());

		cin >> m;

		for(int i = 1;i <= m;i ++){
			cin >> op;
			word[i] = op;
			reverse(op.begin(),op.end());//倒放
			for(int i = 0;i < op.size();i ++){
				if(op[i] >= 'A' && op[i] <= 'Z')op[i] += ('a' - 'A');
			}
			Insert(op,i);
		}
		dfs(0);
	}
	return 0;
}