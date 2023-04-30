#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int n,m,flag;
int a,b;
// int num[maxn / 10];
string word;
struct tree
{
	int next[26];//指向下一个字符的位置
	int sum;//表示当前的这个字母有多少个字符串占据，若等于1，就说明到这个字母，前面就是单词的特殊前缀
	// int end;//是否最后一个，是的话就把到这里的前缀当做特殊前缀
	vector<int> ans;//存储第几篇文章
}t[maxn];
int id;

void Insert(string str,int text){
	int p = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
		t[p].sum ++;
	}
	t[p].ans.push_back(text);//标记第几篇文章出现
}

void Search(string str){
	// cout << str << endl;
	int p = 0;
	// int cnt = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		p = t[p].next[to];
		if(i == len - 1){
			for(int j = 0;j < t[p].ans.size();j ++){
				if(j > 0 && t[p].ans[j] == t[p].ans[j - 1])continue;
				cout << t[p].ans[j] << " ";
			}
		}
		// if(t[p].end && i != len - 1){
		// 	// cout << str.substr(0,i + 1) << endl;
		// 	cnt += t[p].end;
		// }else if(i == len - 1 && t[p].sum > 0)cnt += t[p].sum;
		if(!p)break;//当接下来没有了就跳出去，避免重复计算
	}
	cout << endl;
	// return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while(cin >> n){
			id = 0;
			memset(t,0,sizeof(t));
			
			for(int i = 1;i <= n;i ++){
				cin >> a;
				for(int j = 0;j < a;j ++){
					cin >> word;
					Insert(word,i);
				}
				// Insert(a);
			}

			cin >> m;
			for(int i = 1;i <= m;i ++){
				// cin >> a;
				// for(int j = 0;j < a;j ++){
				// 	cin >> num[i];
				// }
				cin >> word;
				Search(word);
			}
		}
	return 0;
}