#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;

	int flag = 0;

	for(int i = 0;i < n;i ++){
		if(s[i] == 'o')flag ++;
		if(s[i] == 'x'){
			flag = -1;
			break;
		}
	}

	if(flag == -1 || !flag)cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}