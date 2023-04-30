#include <bits/stdc++.h>
using namespace std;

int n,m,t;
int dp[210][210];
struct node
{
	int mi,ti;
	bool operator <(const node&a)const{
		if(mi != a.mi)return mi < a.mi;
		return ti < a.ti;
	}
}p[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m >> t){
		for(int i = 1;i <= n;i ++){
			cin >> p[i].mi >> p[i].ti;
		}
		// sort(p+1,p+1+n);
		memset(dp,0,sizeof(dp));
		// dp[0][0] = 1;
		for(int i = 1;i <= n;i ++){
			for(int j = m;j >= p[i].mi;j --){
				for(int k = t;k >= p[i].ti;k --){
					dp[j][k] = max(dp[j][k],dp[j-p[i].mi][k-p[i].ti] + 1);
				}
			}
		}
		cout << dp[m][t] << endl;
	}
}

//题目大意：有n个愿望，有m钱和t时间，最多能实现几个愿望
//思路：01背包问题，状态转移方程为dp[j][k] = max(dp[j][k],dp[j-m][k-t] + 1),即可解决问题