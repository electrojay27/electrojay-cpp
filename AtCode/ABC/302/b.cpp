#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h,w;
	string str[h];

	cin >> h >> w;
	for (int i = 0;i < h;i ++) {
		cin >> str[i];
	}

	char f[5] = {'s','n','u','k','e'};

	pair<int,int> ans,to;
	for(int i = 0;i < h;i ++) {
		for(int j = 0;j < w;j ++) {
			if(str[i][j] == 's') {
				int cmp = 0;
				int x = i,y = j;
				for(int l = -1;l <= 1;l ++){
					for(int r = -1;r <= 1;r ++){
						while(x >= 0 && y >= 0 && x < h && y < w && cmp <= 4 && str[x][y] == f[cmp]) {
							cmp ++;
							x += i;
							y += j;
						}

						if(cmp == 4 && str[x][y] == f[cmp]){
							for(int o = 0;o <= 4;o ++)
								for(int p = 0;p <= 4;p ++)
									cout << i + o * l + 1 << " " << j + p * r + 1 << "\n";

							return 0;
						}
					}
				}
			}
		}
	}
}