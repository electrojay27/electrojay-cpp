#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int m,n,flag;
int a,b;
int num[maxn / 10];
struct tree
{
	int next[2];//指向下一个字符的位置
	int sum;//表示当前的这个字母有多少个字符串占据，若等于1，就说明到这个字母，前面就是单词的特殊前缀
	int end;//是否最后一个，是的话就把到这里的前缀当做特殊前缀
}t[maxn];
int id;

void Insert(int len){
	int p = 0;
	// int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = num[i];
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
		t[p].sum ++;
	}
	t[p].end ++;//标记结束
}

int Search(int len){
	// cout << str << endl;
	int p = 0;
	int cnt = 0;
	// int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = num[i];
		p = t[p].next[to];
		if(t[p].end && i != len - 1){
			// cout << str.substr(0,i + 1) << endl;
			cnt += t[p].end;
		}else if(i == len - 1 && t[p].sum > 0)cnt += t[p].sum;
		if(!p)break;//当接下来没有了就跳出去，避免重复计算
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while(cin >> m >> n){
			id = 0;
			memset(t,0,sizeof(t));
			
			for(int i = 1;i <= m;i ++){
				cin >> a;
				for(int i = 0;i < a;i ++){
					cin >> num[i];
				}
				Insert(a);
			}

			for(int i = 1;i <= n;i ++){
				cin >> a;
				for(int i = 0;i < a;i ++){
					cin >> num[i];
				}
				cout << Search(a) << endl;
			}
		}
	return 0;
}