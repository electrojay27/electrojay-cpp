#include <iostream>
#include <cstring>
using namespace std;
#define i64 = long long;

int ans[20][20],tmp[20][20],mp[20][20];
int n,m;
int dx[5] = {0, 0, 0, 0, -1};
int dy[5] = {0, 0, -1, 1, 0};

int solve()
{
	for(int i = 1;i < n;i ++){
		for(int j = 1;j <= m;j ++){
			int t = mp[i][j], cnt = 0;
            for (int k = 1; k <= 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                t += tmp[x][y];
            }
            if (t & 1)tmp[i+1][j] = 1;
		}
	}

	int i = n;
    for (int j = 1; j <= m; j++){
        int t = mp[i][j], cnt = 0;
        for (int k = 1; k <= 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            t += tmp[x][y];
        }
        if (t & 1)return -1;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (tmp[i][j] & 1)
                ret++;
    return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> mp[i][j];
		}
	}

	int op = 0x3f3f3f3f;
	for(int i = 0;i < (1 << n);i ++){
		memset(tmp,0,sizeof(tmp));
		for(int j = 1;j <= m;j ++){
			tmp[1][j] = (i >> (j - 1)) & 1;
		}

		int cnt = solve();
		if(cnt == -1){
			continue;
		}else if(op > cnt){
			op = cnt;
			for(int j = 1;j <= n;j ++){
				for(int k = 1;k <= m;k ++){
					ans[j][k] = tmp[j][k];
				}
			}
		}
	}

	if(op == 0x3f3f3f3f){
		cout << "IMPOSSIBLE\n";
	}else{
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				cout << ans[i][j] << " \n"[j == m];
	}
}