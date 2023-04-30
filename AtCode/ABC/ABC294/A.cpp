#include <bits/stdc++.h>
using namespace std;

int n,x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		while(n --){
			cin >> x;
			if(!(x & 1))cout << x << " ";
		}
		cout << endl;
	}
}