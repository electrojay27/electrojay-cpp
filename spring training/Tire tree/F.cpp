#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
string s[maxn];

struct tree
{
	int next[26];//指向下一个字符的位置
	// int sum;//表示当前的这个字母有多少个字符串占据，若等于1，就说明到这个字母，前面就是单词的特殊前缀
	int end;//是否最后一个，是的话就把到这里的前缀当做特殊前缀
	// vector<int> ans;//存储第几篇文章
}t[maxn];
int id;

// struct STR
// {
// 	string Str;
// 	int l;

// 	bool operator <(const STR&t)const{
// 		return l < t.l;
// 	}
// }s[maxn];

void Insert(string str){
	int p = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
	}
	t[p].end = 1;//标记结束
}

int Search(string str){
	int p = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		p = t[p].next[to];
		if(!p)return 0;
	}
	return t[p].end;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size = 0;
	id = 0;
	string op;
	memset(t,0,sizeof(t));
	while(getline(cin,s[size])){
		// s[size].Str = op;
		// s[size].l = op.size();
		Insert(s[size]);
		size ++;
	}

	// sort(s,s + size - 1);//进行排序

	for(int i = 0;i < size;i ++){
		for(int j = 1;j < s[i].size();j ++){
			if(Search(s[i].substr(0,j)) && Search(s[i].substr(j))){
				cout << s[i] << endl;
				break;
			}
		}
	}

	return 0;
}