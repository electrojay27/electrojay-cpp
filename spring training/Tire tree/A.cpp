#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
// char s[2010][25];
vector<string> all;
string s[2010];
struct tree
{
	int next[26];//指向下一个字母的位置
	int sum;//表示当前的这个字母有多少个字符串占据，若等于1，就说明到这个字母，前面就是单词的特殊前缀
	// int end;//是否最后一个，是的话就把到这里的前缀当做特殊前缀
}t[maxn];
int id;

void Insert(string str){
	int p = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		if(!t[p].next[to])t[p].next[to] = ++id;
		p = t[p].next[to];
		t[p].sum ++;
	}
}

int Search(string str){
	int p = 0;
	int cnt = 0;
	int len = str.size();
	for(int i = 0;i < len;i ++){
		int to = str[i] - 'a';
		p = t[p].next[to];
		if(t[p].sum == 1){
			return cnt + 1;
		}
		cnt ++;
	}
	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	id = 0;
	int i = 0;
	string s;
	while(getline(cin,s)){
		Insert(s);
		all.push_back(s);
		i ++;
	}

	for(int j = 0;j < i;j ++){
		cout << all[j] << " " << all[j].substr(0,Search(all[j])) << endl;
	}
	return 0;
}