#include <bits/stdc++.h>

using i64 = long long;

int a[10010];

void Q_sort(int l,int r){
	if(l <= r)return;
	int mid = (l + r) / 2;
	
	
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	for(int i = 1;i <= n;i ++){
		std::cin >> a[i];
	}

	Q_sort(1,n);

	for(int i = 1;i <= n;i ++){
		if(i != n)std::cout << a[i] << " ";
		else std::cout << a[i] << "\n";
	}

	return 0;
}