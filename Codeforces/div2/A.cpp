#include <bits/stdc++.h>
using namespace std;

int t;
string op;
int a[10];
int cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){
			cnt = 0;
			memset(a,0,sizeof(a));
			vector<int> ans;

			cin >> op;
			for(int i = 0;i < 4;i ++){
				if(!a[op[i] - '0'])ans.push_back(op[i] - '0'),cnt++;
				a[op[i] - '0']++;
			}

			if(cnt == 2 && a[ans[0]] == a[ans[1]])cnt++;

			if(cnt == 1){
				cout << -1 << endl;
			}else if(cnt == 2){
				cout << 6 << endl;
			}else if(cnt == 3){
				cout << 4 << endl;
			}else{
				cout << 4 << endl;
			}
		}
	}
	return 0;
}