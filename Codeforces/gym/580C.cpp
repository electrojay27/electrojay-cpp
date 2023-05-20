#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int solve(string s,char c)
{
	if(s.size() == 1){
		return s[0] != c;
	}

	int mid = s.size() / 2;
	int cntl = solve(string(s.begin(),s.begin() + mid),c + 1);
	int cntr = solve(string(s.begin() + mid,s.end()),c + 1);
	cntl +=	mid - count(s.begin() + mid,s.end(),c);
	cntr +=	mid - count(s.begin(),s.begin() + mid,c);

	return min(cntl,cntr);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		int n;
		string s;
		cin >> n >> s;

		cout << solve(s,'a') << "\n";
	}

	return 0;
}