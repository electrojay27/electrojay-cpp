#include <bits/stdc++.h>
using namespace std;
#define ll long long

class CA
{
public:
	ll account[2];
	string name[2];
	double balance[2];

// private:
	void deposit(int xh,double x){
		balance[xh] += x;
		cout << "saving ok!" << endl;
	}
	void withdraw(int xh,double x){
		if(balance[xh] >= x){
			balance[xh] -= x;
			cout << "withdraw ok!" << endl;
		}else cout << "sorry! over limit!" << endl;
	}
	void check(int xh){
		cout << name[xh] << "'s balance is" << balance[xh] << endl;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	CA per;
	double x;
	for(int i = 1;i <= 2;i ++)
	{
		cin >> per.account[i] >> per.name[i] >> per.balance[i];
		per.check(i);
		cin >> x;
		per.deposit(i,x);
		per.check(i);
		cin >> x;
		per.withdraw(i,x);
		per.check(i);
	}
}