#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int maxn = 1e6 + 10;
int n;
int ne[maxn];
int ans[maxn];
int cnt;
string s;

void solve()
{
	cin >> s;
	cout << "Test case #" << cnt ++ << endl;

	s = '0' + s;
	ne[1] = 0;
	for(int i = 2,j = 0;i <= n;i ++)
	{
		while(j && s[i] != s[j + 1])j = ne[j];
		if(s[i] == s[j + 1])j ++;
		if(j && i % (i - j) == 0)
		{
			cout << i << " " << i / (i - j) << endl;
		}
	}

	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cnt = 1;

	while(cin >> n && n)
	{
		solve();
	}
	return 0;
}