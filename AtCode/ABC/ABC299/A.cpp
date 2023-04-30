#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int flag = 0;

	int x = s.find('|');
	int y = s.find('*');
	int z = s.rfind('|');

	if(x < y && y < z)cout << "in\n";
	else cout << "out\n";
	return 0;
}