#include <bits/stdc++.h>

using i64 = long long;

const int maxn = 1e5 + 10;

void solve()
{
	std::string s;
	std::cin >> s;

	for(int i = 0;i < s.size();i ++){
		int to = s[i] - '0';
		if(to % 8 == 0){
			std::cout << "YES\n";
			std::cout << s[i] << "\n";
			return;
		}
	}

	for(int i = 0;i < s.size();i ++){
		for(int j = i + 1;j < s.size();j ++){
			int to = (s[i] - '0') * 10 + s[j] - '0';
			if(to % 8 == 0){
				std::cout << "YES\n";
				std::cout << s[i] << s[j] << "\n";
				return;
			}
		}
	}

	for(int i = 0;i < s.size();i ++){
		for(int j = i + 1;j < s.size();j ++){
			for(int k = j + 1;k < s.size();k ++){
				int to = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
				if(to % 8 == 0){
					std::cout << "YES\n";
					std::cout << s[i] << s[j] << s[k] << "\n";
					return;
				}
			}
		}
	}

	std::cout << "NO\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;
	while(t --){
		solve();
	}

	return 0;
}