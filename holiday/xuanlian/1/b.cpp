#include <bits/stdc++.h>
#define mod 100000000
using namespace std;

using i64 = long long;

int f[101][101][11][11];//有些不可行重复计算

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n1,n2,k1,k2;
	cin >> n1 >> n2 >> k1 >> k2;

	memset(f,-1,sizeof(f));

	function<int(int,int,int,int)> dfs = [&](int x, int y, int a, int b) {
		if (f[x][y][a][b] != -1) return f[x][y][a][b];

		if (!x && !y) return 1;

		int res = 0;

		if (a < k1 && x) {
			res = (res + dfs(x - 1,y,a + 1,0)) % mod;
			// f[x][y][a][b] = (f[x][y][a][b] + dfs(x - 1,y,a + 1,0)) % mod;
		}

		if (b < k2 && y) {
			res = (res + dfs(x,y - 1,0,b + 1)) % mod;
			// f[x][y][a][b] = (f[x][y][a][b] + dfs(x,y - 1,0,b + 1)) % mod;
		}

		
		return f[x][y][a][b] = res;
	};

	cout << dfs(n1,n2,0,0) << "\n";
}