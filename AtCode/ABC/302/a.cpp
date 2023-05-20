#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 a,b;
	cin >> a >> b;

	if(a % b != 0){
		cout << a / b + 1 << "\n";	
	}else{
		cout << a / b << "\n";
	}
}