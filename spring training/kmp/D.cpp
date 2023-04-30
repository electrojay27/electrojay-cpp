#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int maxn = 1e6 + 10;
int ne[maxn];
int num[maxn];
ll ans;
string s;

void solve()
{
	cin >> s;

	int len = s.size();

	num[1] = 1;
	ne[1] = 0;
	for(int i = 2,j = 0;i <= len;i ++)
	{
		while(j && s[i - 1] != s[j])j = ne[j];
		if(s[i - 1] == s[j])j ++;
		ne[i] = j;
		num[i] = num[j] + 1;
		// cout << num[i] << " " << i << endl;
	}

	// cout << endl;

	ans = 1;

	for(int i = 2,j = 0;i <= len;i ++)
	{
		while(j && s[i - 1] != s[j])j = ne[j];
		if(s[i - 1] == s[j])j ++;
		while(j > i / 2)j = ne[j];
		// cout << num[j] << " " << i << endl;
		ans = ans * (num[j] + 1) % mod;
	}

	cout << ans << endl;

	// cout << endl;
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