#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
string word[205];
int n,m;
string s;
vector<int> arr[maxn];
int ne[maxn];
int dp[maxn] = {0};

void kmp(int x)
{
	int m = word[x].size();

	ne[1] = 0;
	for(int i = 2,j = 0;i <= m;i ++)
	{
		while(j && word[x][i - 1] != word[x][j])j = ne[j];
		if(word[x][i - 1] == word[x][j])j ++;
		ne[i] = j;
	}

	for(int i = 1,j = 0;i <= n;i ++)
	{
		while(j && (j == m || s[i - 1] != word[x][j]))j = ne[j];
		if(s[i - 1] == word[x][j])j ++;
		if(j == m)arr[i].push_back(m);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	while(cin >> word[cnt]){
		if(word[cnt][0] == '.')break;
		cnt ++;
	}

	string x;
	while(cin >> x)s += x;

	n = s.size();

	for(int i = 0;i < cnt;i ++)kmp(i);

	dp[0] = 1;
	int ans = 0;

	for(int i = 1;i <= n;i ++)
	{
		for(int j = 0;j < arr[i].size();j ++)
		{
			if(dp[i - arr[i][j]])dp[i] = 1;
		}
		if(dp[i])ans = max(ans,i);
	}

	cout << ans << endl;

	return 0;
}