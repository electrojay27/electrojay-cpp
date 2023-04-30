#include <bits/stdc++.h>
using namespace std;

int n,a,b,c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		while(n --){
			cin >> a >> b >> c;
			if(a + b == c)cout << "+" << endl;
			else if(a - b == c)cout << "-" << endl;
		}
	}
	return 0;
}