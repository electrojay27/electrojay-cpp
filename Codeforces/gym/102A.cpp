#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	vector<int> a(n);
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}

	int u,v;
	vector<vector<int>> mp(n + 1,vector<int>(n + 1,0));
	for(int i = 0;i < m;i ++){
		cin >> u >> v;
		mp[u][v] = 1;
		mp[v][u] = 1;
	}

	int ans = -1;
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j <= n;j ++){
			if(mp[i][j]){
				for(int k = 1;k <= n;k ++){
					if(mp[i][k] && mp[k][j]){
						if(ans == -1){
							ans = a[i - 1] + a[k - 1] + a[j - 1];
						}else{
							ans = min(ans,a[i - 1] + a[k - 1] + a[j - 1]);
						}
					}
				}
			}
		}
	}

	cout << ans << "\n";
}