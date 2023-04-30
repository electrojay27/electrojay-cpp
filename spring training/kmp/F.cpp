#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int maxn = 1e6 + 10;
int ne[maxn];
int len;
int ans;
int cnt;
string s;

bool judge(int x)
{
	for(int i = x + 1,j = 0;i <= len - x;i ++)
	{
		while(j && s[i] != s[j + 1])j = ne[j];
		if(s[i] == s[j + 1])j ++;
		if(j == x)return true;
	}

	return false;
}

void solve()
{
	cin >> s;

	len = s.size();
	s = '0' + s;

	ne[1] = 0;
	for(int i = 2,j = 0;i <= len;i ++)
	{
		while(j && s[i] != s[j + 1])j = ne[j];
		if(s[i] == s[j + 1])j ++;
		ne[i] = j;
	}

	ans = ne[len];
	while(ans){
		if(judge(ans))break;
		ans = ne[ans];
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while(t --)
	{
		solve();
	}
	return 0;
}