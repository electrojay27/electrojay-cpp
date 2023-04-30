#include <bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for(int i = 0;i <= n;i ++){
		std::cin >> a[i];
	}

	int flag = 0;

	for(int i = 0;i <= n;i ++){
		if(!a[i] && i != n)continue;
		if(!flag){
			flag = 1;
			if(i == n){
				std::cout << a[i] << "\n";
				continue;
			}
			if(fabs(a[i]) == 1){
				if(n - i == 1)std::cout << (a[i] == 1 ? '+' : '-') << 'x';
				else if(a[i] < 0)std::cout << '-' << "x^" << n - i;
				else std::cout << "x^" << n - i;
				continue;
			}
			std::cout << a[i] << "x^" << n - i;
		}else{
			if(i == n){
				if(!a[i]){
					int cnt = 0;
					for(auto it : a)if(!it)cnt ++;
					if(cnt == n + 1)std::cout << "0\n";
					break;
				}
				if(a[i] < 0)std::cout << a[i] << "\n";
				else std::cout << "+" << std::fabs(a[i]) << "\n";
				break;
			}

			char cmp;
			if(a[i] < 0)cmp = '-';
			else cmp = '+';
			if(fabs(a[i]) == 1){
				if(n - i == 1)std::cout << cmp << "x";
				else std::cout << cmp << "x^" << n - i;
			}else{
				if(n - i == 1)std::cout << cmp << fabs(a[i]) << "x";
				else std::cout << cmp << fabs(a[i]) << "x^" << n - i;
			}
		}
	}

	return 0;
}