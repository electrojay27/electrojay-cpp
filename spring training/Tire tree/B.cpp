#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
int T,n,flag;
string s;
struct tree
{
	int next[10];//指向下一个字符的位置
	int sum;//表示当前的这个字母有多少个字符串占据，若等于1，就说明到这个字母，前面就是单词的特殊前缀
	int end;//是否最后一个，是的话就把到这里的前缀当做特殊前缀
}t[maxn];
int id;

void Insert(string str){
	int p = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - '0';
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
		t[p].sum ++;
		if(i == len - 1)t[p].end = 1;//标记结束
	}
}

int Search(string str){
	// cout << str << endl;
	int p = 0;
	int cnt = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - '0';
		p = t[p].next[to];
		if(t[p].end && i != len - 1){
			// cout << str.substr(0,i + 1) << endl;
			return 0;
		}else if(i == len - 1 && t[p].sum > 1)return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while(T --){
			id = 0;
			flag = 1;
			memset(t,0,sizeof(t));
			vector<string> all;
			cin >> n;
			for(int i = 1;i <= n;i ++){
				cin >> s;
				Insert(s);
				if(i != 1){
					if(!Search(s))flag = 0;
				}
			}
			// for(int i = 0;i < all.size();i ++){
			// 	int t = Search(all[i]);
			// 	if(!t){
			// 		flag = 0;
			// 		break;
			// 	}
			// }
			if(flag)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	return 0;
}