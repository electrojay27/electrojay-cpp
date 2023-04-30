#include <bits/stdc++.h>

using i64 = long long;

const int maxn = 1e5 + 10;

void solve()
{
	std::string s;
	std::cin >> s;

	int a = 0,b = 0;

	for(int i = 0;i < s.size();i ++){
		if(!a && s[i] == 'A' && s[i + 1] == 'B'){
			a = 1;
			if(s[i + 2] == 'A')i += 2;
			else i ++;
		}
		if(!b && s[i] == 'B' && s[i + 1] == 'A'){
			b = 1;
			if(s[i + 2] == 'B')i += 2;
			else i ++;
		}
	}

	if(a && b){
		std::cout << "YES\n";
		return;
	}else if(!a && !b){
		std::cout << "NO\n";
		return;
	}

	a = b = 0;

	for(int i = s.size() - 1;i >= 0;i --){
		if(!a && s[i] == 'A' && s[i - 1] == 'B'){
			a = 1;
			if(s[i - 2] == 'A')i -= 2;
			else i --;
		}
		if(!b && s[i] == 'B' && s[i - 1] == 'A'){
			b = 1;
			if(s[i - 2] == 'B')i -= 2;
			else i --;
		}
	}

	if(a && b)std::cout << "YES\n";
	else std::cout << "NO\n"; 
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