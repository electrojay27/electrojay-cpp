#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define i64 long long

const int maxn = 1000;
int dp[maxn];
int C,G,x;
int l,r;
int wei[30];//砝码的质量

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> C >> G){
		l = r = 0;
		int ans = 0;
		memset(dp,0,sizeof(dp));//初始化
		for(int i = 1;i <= C;i ++){
			cin >> x;
			if(x > 0)l += x;//正数去左边
			else r -= x;//负数去右边
		}
		for(int i = 1;i <= G;i ++){
			cin >> wei[i];
		}

		dp[0] = 1;//初始化0这个位置，避免无法计算
		for(int i = 1;i <= 2 * G;i ++){//为什么要遍历两边，是因为第一遍只是将各个砝码放到最基本的位置上，其他的
			for(int j = r - l;j >= wei[i % G];j--){
				if(!dp[j] && dp[j-wei[i % G]]){
					dp[j] = 1;
					if(j == r - l)ans ++;
				}
			}
		}
		cout << ans << endl;
	}
}