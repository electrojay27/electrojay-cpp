#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Accout
{
private:
	int balance;
	double rate;
	int number;
	char type;
public:
	Accout(){};
	Accout(int num,char ty,int ba){
		balance = ba;
		number = num;
		type = ty;
		rate = 0.005;
	}
	void interest_calculation(){
		balance += balance * rate;
		cout << "Account=" << number << "--sum=" << balance << "\n";
	}
	void Sreach(){
		cout << "Account=" << number << "--";
		if(type == 'P'){
			cout << "Person--";
		}else cout << "Enterprise--";

		cout << "sum=" << balance << "--";
		cout << "rate=" << fixed << setprecision(3) << rate << "\n";
	}
	Accout(const Accout & current){
		balance = current.balance;
		number = current.number + 50000000;
		type = current.type;
		rate = 0.015;
	}
};

void solve()
{
	int number,balance;
	char type;
	cin >> number >> type >> balance;
	Accout current(number,type,balance);
	Accout regular(current);

	cin >> type;
	if(type == 'C'){
		current.interest_calculation();
	}else current.Sreach();

	cin >> type;
	if(type == 'C'){
		regular.interest_calculation();
	}else regular.Sreach();
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