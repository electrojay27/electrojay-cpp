#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 10;
string s;
int vis[26];
int b[maxn];
int e[maxn];
ll ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> s){
		ans = 0;

		int len = s.size();
		s = '\0' + s;

		for(int i = 0;i < 26;i ++){
			vis[i] = 0;
		}
		for(int i = 1;i <= len;i ++){
			b[i] = vis[s[i] - 'a'];
			vis[s[i] - 'a'] = i;
		}

		for(int i = 0;i < 26;i ++){
			vis[i] = len + 1;
		}
		for(int i = len;i > 0;i --){
			e[i] = vis[s[i] - 'a'];
			vis[s[i] - 'a'] = i;
		}

		for(int i = 1;i <= len;i ++){
			ans += (i - b[i]) * (e[i] - i);
		}
		cout << ans << endl;
	}
	return 0;
}