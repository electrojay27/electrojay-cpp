#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	cout << s[(s.size() + 1) / 2 - 1] << "\n";

	return 0;
}