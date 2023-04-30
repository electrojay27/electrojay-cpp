#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int maxn = 1e6 + 10;
int n,t;
int ne[maxn];
string ans,op;


void solve()
{	
	cin >> op;
	if(t == 1)ans += op;
	else{
		int lena = ans.size();
		int lenb = op.size();
		ne[1] = 0;
		for(int i = 2,j = 0;i <= lenb;i ++)
		{
			while(j && op[i - 1] != op[j])j = ne[j];
			if(op[i - 1] == op[j])j ++;
			ne[i] = j;
		}

		for(int i = max(1,lena-lenb+1),j = 0;i <= lena;i ++)//优化时间，起点位置要考虑好
		{
			while(j && ans[i - 1] != op[j])j = ne[j];
			if(ans[i - 1] == op[j])j ++;
			// if(j == op.size() && i != ans.size())j = ne[j];

			if(i == lena)ans += op.substr(j);
		}
	}

	if(t == n)cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for(t = 1;t <= n;t ++)
	{
		solve();
	}
	return 0;
}