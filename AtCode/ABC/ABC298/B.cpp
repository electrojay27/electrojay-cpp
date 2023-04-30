#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

using i64 = long long;

int a[110][110];
int b[110][110];
int vis[110][110];
int goal = 0,cnt = 0;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	memset(vis,0,sizeof(vis));
	queue<pii> q;


	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
			if(a[i][j] == 1)q.push({i,j}),goal ++;
		}
	}

	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			cin >> b[i][j];
			if(a[i][j] == 1 && b[i][j] == 1)vis[i][j] = 1,cnt ++;
		}
	}

	while(!q.empty()){
		pii to = q.front();
		q.pop();

		int x = to.first;
		int y = to.second;

		if(vis[x][y] == 1)continue;

		int k = 4;
		while(k --){
			int temp = x;
			x = n + 1 - y;
			y = temp;
			if(b[x][y] && !vis[x][y]){
				cnt ++;
				break;
			}
		}
	}

	if(cnt != goal)cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}