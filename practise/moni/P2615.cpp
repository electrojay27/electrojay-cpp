#include <bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> k(n + 1,std::vector<int>(n + 1,0));
	int x = 1,y = (n - 1) / 2 + 1;
	for(int i = 1;i <= n * n; i++){
		if(i == 1)k[x][y] = i;
		else{
			if(x == 1 && y != n){
				k[n][y + 1] = i;
				x = n;
				y ++;
			}else if(y == n && x != 1){
				k[x - 1][1] = i;
				x --;
				y = 1;
			}else if(x == 1 && y == n){
				k[x + 1][y] = i;
				x ++;
			}else{
				if(!k[x - 1][y + 1]){
					k[x - 1][y + 1] = i;
					x --,y ++;
				}else{
					k[x + 1][y] = i;
					x ++;
				}
			}
		}
	}

	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(j != n)std::cout << k[i][j] << " ";
			else std::cout << k[i][j] << "\n";
		}
	}

	return 0;
}