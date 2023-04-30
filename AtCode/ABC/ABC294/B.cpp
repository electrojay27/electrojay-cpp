#include <bits/stdc++.h>
using namespace std;

int n,m,x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <=m;j ++){
				cin >> x;
				if(x)cout << char(x + 'A' - 1);
				else cout << '.';
			}cout << endl;
		}
	}
	return 0;
}