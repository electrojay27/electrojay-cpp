#include <bits/stdc++.h>

using i64 = long long;

struct node
{
	int a,b,g,k;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<node> carpet(n);
	for(int i = 0;i < n;i ++){
		std::cin >> carpet[i].a >> carpet[i].b >> carpet[i].g >> carpet[i].k;
	}

	int x,y;
	std::cin >> x >> y;

	int ans = -1;
	for(int i = 0;i < n;i ++){
		if(carpet[i].a <= x && x <= carpet[i].a + carpet[i].g){
			if(carpet[i].b <= y && y <= carpet[i].b + carpet[i].k){
				ans = i + 1;
			}
		}
	}

	std::cout << ans << "\n";
}