#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n;
string s;
int ne[maxn];

//设想一下，我们要令目标字符串最长,而且给出的字符串是目标的自我连接版本的子串,那么给出一个cabca
//它的目标字符串最小是cab，它的两倍就是cabcab,少了一个，但是最长前后缀是ca，长度为2
//就可以推理出 我们先求的所给串的最长的前后缀，然后就用n减去这个长度就是答案
//但是我们要考虑它不只是两倍呢？而且最后求求差要怎么去求
//不管几倍，我们都可以通过求最长前后缀来确定ans，但是我们该怎么求差，因为它不可能少了中间的部分
//不然就是另外一回事了，所以可以确定整体的最长前后缀就是目标的几倍减去缺少的字母数量

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> s)
	{
		s = '0' + s;

		ne[1] = 0;

		for(int i = 2,j = 0;i <= n;i ++)
		{
			while(j && s[i] != s[j + 1])j = ne[j];
			if(s[i] == s[j + 1])j ++;
			ne[i] = j;
		}

		cout << n - ne[n] << endl;
	}
	return 0;
}
