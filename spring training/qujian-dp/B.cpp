#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[110][110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string op;
	while(cin >> op){
		memset(dp,0,sizeof(dp));

		if(op == "end")break;
		op = '0' + op;

		for(int i = 1;i < op.size();i ++){
			for(int begin = 1;begin + i <= op.size();begin ++){
				int end = begin + i - 1;
				if(op[begin] == '[' && op[end] == ']' || op[begin] == '(' && op[end] == ')'){
					dp[begin][end] = dp[begin + 1][end - 1] + 2;
				}
				for(int k = begin;k < end;k ++){
					dp[begin][end] = max(dp[begin][k] + dp[k + 1][end],dp[begin][end]);
				}
			}
		}

		cout << dp[1][op.size() - 1] << endl;
	}

	return 0;
}