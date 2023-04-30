#include <bits/stdc++.h>
using namespace std;

int n,flag;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n){
		flag = 0;
		string op;
		for(int i = 1;i <= n;i ++){
			cin >> op;
			if(flag)continue;
			if(op == "and"||op == "you"||op == "the"||op == "that"||op == "not")flag = 1;
		}
		if(flag)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}