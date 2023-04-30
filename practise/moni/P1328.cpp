#include <bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n,na,nb;
	std::cin >> n >> na >> nb;

	std::vector<int> a(na);
	std::vector<int> b(nb);

	for(int i = 0;i < na;i ++)std::cin >> a[i];
	for(int i = 0;i < nb;i ++)std::cin >> b[i];

	int ansa = 0,ansb = 0;
	for(int i = 0;i < n;i ++){
		if(a[i%na] == b[i%nb])continue;
		switch(a[i%na]){
			case 0:if(b[i%nb] == 1 || b[i%nb] == 4)ansb ++;else ansa ++;break;
			case 1:if(b[i%nb] == 2 || b[i%nb] == 4)ansb ++;else ansa ++;break;
			case 2:if(b[i%nb] == 0 || b[i%nb] == 3)ansb ++;else ansa ++;break;
			case 3:if(b[i%nb] == 0 || b[i%nb] == 1)ansb ++;else ansa ++;break;
			case 4:if(b[i%nb] == 2 || b[i%nb] == 3)ansb ++;else ansa ++;break;
		}
	}

	std::cout << ansa << " " << ansb << "\n";

	return 0;
}