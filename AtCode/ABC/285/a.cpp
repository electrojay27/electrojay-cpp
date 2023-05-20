#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b;
	cin >> a >> b;

	if(a != 2 * b && a != 2 * b + 1 && b != 2 * a && b != 2 * a + 1){
		cout << "No\n";
	}else cout << "Yes\n";
}