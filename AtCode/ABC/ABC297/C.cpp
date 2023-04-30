#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n,m;
string op;

void solve()
{
	while(n --){
		cin >> op;
		for(int i = 0;i < m - 1;i ++){
			if(op[i] == op[i + 1] && op[i] == 'T'){
				op[i] = 'P';
				op[i + 1] = 'C';
				i ++;
			}
		}

		cout << op << endl;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		solve();
	}
	return 0;
}