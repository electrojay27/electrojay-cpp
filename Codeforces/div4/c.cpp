#include <bits/stdc++.h>
using namespace std;

int t,n,x;
string op;
bool vis[2010];
// int a[110],b[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){
			cin >> n;
			cin >> op;
			int flag = 1;
			memset(vis,0,sizeof(vis));
			for(int i = 0;i < n;i ++){
				if(!vis[i]){
					vis[i] = 1;
					for(int j = i + 1;j < n;j ++){
						if(op[i] == op[j]){
							if(j % 2 == i % 2)vis[j] = 1;
							else{
								flag = 0;
								break;
							}
						}
					}
				}
				if(!flag)break;
			}
			if(!flag)cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	return 0;
}