#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int m[maxn];
int n,c;
int ans;

void dfs(int x){
	if(x == 0)return;

	if(ans + m[x] > c){
		dfs(x - 1);
	}else{
		ans += m[x];
		dfs(x - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> c){
		ans = 0;

		for(int i = 1;i <= n;i ++)cin >> m[i];

		sort(m + 1,m + 1 + n);

		dfs(n);

		cout << ans << endl;
	}
	return 0;
}