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

	int a = 0,b = 0;
	for(int i = 0;i < n;i ++){
		if(s[i] == 'T')a ++;
		else b ++;
	}

	if(a == b){
		cout << (s[n - 1] == 'T' ? 'A' : 'T') << "\n";
	}else if(a > b){
		cout << "T\n";
	}else cout << "A\n";
}