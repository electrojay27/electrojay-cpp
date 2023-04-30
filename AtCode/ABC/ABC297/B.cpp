#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n,m;
string op;

void solve()
{
	int r = 0,b = 0,b1,b2;

	for(int i = 0;i < op.size();i ++){
		if(op[i] == 'K' && (!r || r == 2)){
			cout << "No" << endl;
			return;
		}
		if(op[i] == 'R'){
			r ++;
		}
		if(op[i] == 'B'){
			if(!b)b1 = i;
			else b2 = i;
			b ++;
		}
	}

	if(b1 % 2 != b2 % 2){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> op){
		solve();
	}
	return 0;
}