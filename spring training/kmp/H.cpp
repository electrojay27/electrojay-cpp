#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int maxn = 1e6 + 10;
char dog[20][5] = {"doge","Doge","dOge","doGe", "dogE", "DOge", "DOGe", "DOGE","DOgE","DoGE","DoGe","DogE","dOGE","dOgE","dOGe","doGE"};
int len;
int ans;
int cnt;
string s;

int kmp(int x)
{	
	int ret = 0;
	int len = s.size();
	for(int i = 1,j = 0;i <= len;i ++){
		while(j && s[i - 1] != dog[x][j])j = 0;
		if(s[i - 1] == dog[x][j])j ++;
		if(j == 4)ret ++,j = 0;
	}
	return ret;
}

void solve()
{	
	ans = 0;
	while(cin >> s)
	{
		for(int i = 0;i < 16;i ++)
		{
			ans += kmp(i);
		}
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	while(t --)
	{
		solve();
	}
	return 0;
}