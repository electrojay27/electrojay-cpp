#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string op;
	cin >> op;

	for(int i = 0; i < op.size(); i++){
		if(op[i] == '1')op[i] = '0';
		else op[i] = '1';
	}

	cout << op << endl;
	return 0;
}