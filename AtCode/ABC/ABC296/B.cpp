#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	string op[8];
	int cnt = 0;
	while(cin >> op[cnt]){
		cnt ++;
		if(cnt == 8)break;
	}

	for(int i = 7;i >= 0;i --)
	{
		for(int j = 0;j < 8;j ++)
		{
			if(op[i][j] == '*'){
				cout << char(j + 'a') << 8 - i << endl;
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	return 0;
}