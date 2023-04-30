#include <bits/stdc++.h>
using namespace std;

class Account
{
private:
    static float count; // 账户总余额
    static float interestRate;
    string a,b;
    float balance;
public:
    Account(string ac, string na, float ba);
    ~Account();
    void deposit(float amount); // 存款
    void withdraw(float amount); // 取款
    float getBalance(); // 获取账户余额
    void show(); // 显示账户所有基本信息
    static void setCount(float x);
    static float getCount(); // 获取账户总余额
    static void setInterestRate(float rate); // 设置利率
    static float getInterestRate(); // 获取利率
    friend void update(Account& a);
};
float Account :: interestRate = 0;
float Account :: count = 0;
Account::Account(string ac, string na, float ba):a(ac),b(na),balance(ba){};
Account::~Account(){}

void Account::deposit(float amount){
	balance += amount;
}

void Account::withdraw(float amount){
	balance -= amount;
	count += balance;
}

float Account::getBalance(){
	return balance;
}

void Account::show()
{
	cout << a << " " << b << " ";
}

void Account::setCount(float x)
{
	count = x;
}

float Account::getCount()
{
	return count;
}

void Account::setInterestRate(float rate){
	interestRate = rate;
}

float Account::getInterestRate(){
	return interestRate;
}

void update(Account& a)
{	
	a.balance += a.balance * a.interestRate;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	float rate;
	cin >> rate;
	Account::setInterestRate(rate);
	Account::setCount(0);
	int n;
	cin >> n;
	Account ** p = new Account*[n];
	string ac,na;
	float ba;
	float am1,am2;
	for(int i = 0;i < n;i ++){
		cin >> ac >> na >> ba >> am1 >> am2;
		p[i] = new Account(ac,na,ba);
		p[i]->show();
		p[i]->deposit(am1);
		cout << p[i]->getBalance() << " ";
		update(*p[i]);
		cout << p[i]->getBalance() << " ";
		p[i]->withdraw(am2);
		cout << p[i]->getBalance() << "\n";
	}

	cout << Account::getCount() << "\n";

	if(!p){
		for(int i = 0;i < n;i ++){
			delete p[i];
		}
		delete p;
	}

	return 0;
}