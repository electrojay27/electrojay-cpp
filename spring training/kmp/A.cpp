#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
string s1,s2;
int ne[maxn];

void solve()
{
	int l1 = s1.size();
	int l2 = s2.size();

	s1 = '0' + s1;
	s2 = '0' + s2;

	ne[1] = 0;//初始化

	for(int i = 2,j = 0;i <= l2;i ++)
	{
		while(j && s2[i] != s2[j + 1])j = ne[j];
		if(s2[i] == s2[j + 1])j ++;
		ne[i] = j;
	}

	for(int i = 1,j = 0;i <= l1;i ++)
	{
		while(j && s1[i] != s2[j + 1])j = ne[j];
		if(s1[i] == s2[j + 1])j ++;
		if(j == l2)cout << i - l2 + 1 << endl;
	}

	for(int i = 1;i <= l2;i ++)cout << ne[i] << " ";

	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> s1 >> s2)
	{
		solve();
	}
	return 0;
}