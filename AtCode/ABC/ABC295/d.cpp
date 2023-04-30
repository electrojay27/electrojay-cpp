#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,x,ans,flag;
string s;
int cnt[10];
int vis[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> s){
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));

		for(int i = 0;i < s.size();i ++){
			cnt[s[i] - '0']++;
		}
		for(int i = 0;i < 10;i ++){
			if(cnt[i] % 2)break;
			if(i == 9)ans ++,flag = 0;
			vis[s[i] - '0'] = 1;
		}

		// int l = 0,r = s.size() - 1;
		for(int r = s.size() - 1,l = 0;r >= l;r --){
			int to = s[r] - '0';
			cnt[to] --;
			if(cnt[to] % 2){
				vis[r] = 0;
				continue;
			}
			if(cnt[to] % 2){
				vis[to] = 1;
				for(int i = 0;i < 10;i ++){
					if(!vis[i])break;
					else ans ++;
				}
			}
		}

		for(int r = s.size() - 1,l = 0;l <= r;l ++){
			int to = s[l] - '0';
			cnt[to] ++;
			if(cnt[to] % 2){
				vis[l] = 0;
				continue;
			}
			if(cnt[to] % 2){
				vis[to] = 1;
				for(int i = 0;i < 10;i ++){
					if(!vis[i])break;
					else ans ++;
				}
			}
		}

		for(int r = s.size() - 1,l = 0;r > l;){
			while(cnt[s[l] - '0'] % 2 != 0){
				l ++;
			}
			vis[s[l] - '0'] = 1;
			for(int i = 0;i < 10;i ++){
				if(!vis[i])break;
				else ans ++;
			}
			while(cnt[s[r] - '0'] % 2 != 0){
				r ++;
			}
			vis[s[r] - '0'] = 1;
			for(int i = 0;i < 10;i ++){
				else ans ++;
			}
		}
	}
	return 0;
}