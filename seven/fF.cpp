#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[35];

void dfs(int day,int id){

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		memset(vis,0,sizeof(vis));
		for(int i = 1;i < n;i ++){
			dfs(i,i + 1);
		}
	}
	return 0;
}