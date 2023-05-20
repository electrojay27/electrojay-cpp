#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class BaseAccount
{
protected:
	string name;
	string accout;
	int balance;
public:
	BaseAccount():balance(0){};
	BaseAccount(string na,string ac,int ba)	{
		name = na;
		accout = ac;
		balance = ba;
	}
	void deposit(int x){
		balance += x;
	}
	virtual void withdraw(int x){
		if(balance - x >= 0){
			balance -= x;
		}else{
			cout << "insufficient\n";
		}
	}
	virtual void display(){
		cout << name << " ";
		cout << accout << " ";
		cout << "Balance:" << balance << "\n";
	}
};

class BasePlus:public BaseAccount
{
private:
	int limit;
public:
	BasePlus(string na,string ac,int ba){
		name = na;
		accout = ac;
		balance = ba;
		limit = 5000;
	}
	virtual void withdraw(int x){
		if(balance - x >= 0){
			balance -= x;
		}else if(limit >= x - balance){
			limit -= x - balance;
			balance = 0;
		}else{
			cout << "insufficient\n";
		}
	}
	virtual void display(){
		cout << name << " ";
		cout << accout << " ";
		cout << "Balance:" << balance << " ";
		cout << "limit:" << limit << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	BaseAccount *p;
	while(t --){
		string name,accout;
		int balance;
		cin >> name >> accout >> balance;

		if(accout.substr(0,2) == "BA"){
			p = new BaseAccount(name,accout,balance);
		}else{
			p = new BasePlus(name,accout,balance);
		}

		for(int i = 0;i < 2;i ++){
			int x,y;
			cin >> x >> y;
			p->deposit(x);
			p->withdraw(y);
		}

		p->display();
	}

	return 0;
}