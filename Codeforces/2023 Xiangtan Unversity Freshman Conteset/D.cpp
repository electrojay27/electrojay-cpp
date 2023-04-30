#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool judge(i64 x){
	if(x == 1)return false;
	if(x == 2)return true;
	for(int i = 2;i * i <= x;i ++){
		if(x % i == 0)return false;
	}

	return true;
}

void solve()
{
	i64 A,B,C;
	cin >> A >> B >> C;

	if(!(A % 2) && !(B % 2) && !(C % 2)){
		cout << "R" << endl;
		return;
	}

	if(B % 2 == 0)swap(A,B);
	if(C % 2 == 0)swap(A,C);

	if(!((A + B + C) % 2)){
		if((!A || B == C && B == 1) && judge(B + C)){
			cout << "R" << endl;
			return;
		}else if(A && judge(A + B) && judge(A + C)){
			cout << "R" << endl;
			return;
		}
	}

	cout << "P" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve();
	}

	return 0;
}