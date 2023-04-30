#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxn = 1e5 + 10;
i64 ne[maxn],num[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	while(cin >> s){
		memset(ne,0,sizeof(ne));
		memset(num,0,sizeof(num));
		i64 ans = 0;
		int n = s.size();

		for(int i = 2,j = 0;i <= n;i ++){
			while(j && s[i - 1] != s[j])j = ne[j];
			if(s[i - 1] == s[j])j ++;
			ne[i] = j;
			num[i] = num[j] + j;
			ans += num[i];
		}

		cout << ans << endl;
	}

	return 0;
}