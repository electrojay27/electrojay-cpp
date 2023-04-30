#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int n,m;
char key1[10],key2[10],key3[10];
struct trie
{
	int next[10];//十个数字
	int end;//标记结束以及结束符号
}t[maxn];
bool vis[maxn];
int id = 0;
vector<int> ans;

void Insert(string str,int x){
	int p = 0;
	for(int i = 0;i < str.size();i ++){
		int to = str[i] - '0';
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
	}
	t[p].end = x;//第几个关键字
}

void Search(string str){
	int p = 0;
	for(int i = 0;i <= str.size();i ++){
		int to = str[i] - '0';
		p = t[p].next[to];
		if(!p)return;
		if(t[p].end && !vis[t[p].end])ans.push_back(t[p].end),vis[t[p].end] = true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while(cin >> m >> n){
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		id = 0;

		string s,op;
		for(int i = 1;i <= m;i ++){
			cin >> op;
			s += op;
		}

		// cin.get();
		for(int i = 1;i <= n;i ++){
			// cin >> key;//[key
			// cin >> key;//No.
			// cin >> key;//数字]
			// cout << op << endl;
			cin >> key1 >> key2 >> key3;
			cin >> op;
			// op = op.substr(op.find("]",0)+2);
			Insert(op,i);
		}

		for(int i = 0;i < s.size();i ++){
			op = s.substr(i);
			Search(op);
		}

		if(ans.empty())cout << "No key can be found !" << "\n";
		else{
			cout << "Found key:";
			for(int i = 0;i < ans.size();i ++){
				cout << " [Key No. " << ans[i] << "]";
			}
			cout << "\n";
		}
	}
	return 0;
}