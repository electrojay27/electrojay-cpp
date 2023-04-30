#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);

	while(cin >> n){
		if(n & 1 || n == 2)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
//题目大意：切一个重量为n的西瓜，将其分成两个偶数
//就是能不能被2整除，当然，2是一个例外