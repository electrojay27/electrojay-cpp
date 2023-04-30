#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 n;
void solve(int x)
{
	cin >> n;
	i64 op = sqrt(n);
	if(op % 2){
		if(op * op == n){
			cout << "Case " << x <<  ": 1 " << op << endl;
		}else{
			if(n - op * op <= op + 1){
				cout << "Case " << x <<  ": " << n - op * op << " " << op + 1 << endl;
			}else{
				cout << "Case " << x <<  ": " << op + 1 << " " << (op + 1) * (op + 1) - n + 1 << endl;
			}
		}
	}else{
		if(op * op == n){
			cout << "Case " << x <<  ": " << op << " " << 1 << endl;
		}else{
			if(n - op * op <= op + 1){
				cout << "Case " << x <<  ": " << op + 1 << " " << n - op * op << endl;
			}else{
				cout << "Case " << x <<  ": " << (op + 1) * (op + 1) - n + 1 << " " << op + 1 << endl;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for(int i = 1;i <= t;i ++){
		solve(i);
	}
	return 0;
}