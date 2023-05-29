#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CPeople
{
protected:
	char id[20];
	char name[10];
public:
	CPeople(){}
};

class CInternetUser:public CPeople
{
protected:
	char password[20];
public:
	CInternetUser(){}
	void registerUser(char N[],char I[],char P[]) {
		strcpy(this->id,I);
		strcpy(this->name,N);
		strcpy(this->password,P);
	}
	bool login(char I[],char P[]) {
		return (!strcmp(this->id,I))&&(!strcmp(this->password,P));
	}
};

class CBankCustomer:public CPeople
{
protected:
	double balance;
public:
	CBankCustomer(){}
	void openAccount(char N[],char I[]) {
		strcpy(this->name,N);
		strcpy(this->id,I);
	}
	void deposit(double m) {
		balance += m;
	}
	bool withdraw(double m) {
		if (balance >= m) {
			balance -= m;
			return 1;
		} else {
			return 0;
		}
	}
};

class CInternetBankCustomer:public CInternetUser,public CBankCustomer
{
protected:
	double balance,lbalance,nowprofit,interest,linterest;
public:
	CInternetBankCustomer(){balance = 0;linterest = 0;lbalance = 0;}
	void setInterest(double i) {
		linterest=this->interest;
		this->interest=i;
	}
	void calculateProfit(){
		nowprofit = lbalance * linterest * 0.0001;
		balance += nowprofit;
		lbalance = balance;
	}
	bool login(char I[],char P[]){
		return (!strcmp(I,CInternetUser::id))&&(!strcmp(P,this->password))&&(!strcmp(CBankCustomer::name,CInternetUser::name))&&(!strcmp(CBankCustomer::id,CInternetUser::id));
	}
	bool deposit(double m){
		if(m > CBankCustomer::balance)return 0;

		balance+=m;
		CBankCustomer::withdraw(m);
		return 1;			
	}
	bool withdraw(double m){
		if(m > balance)return 0;

		balance -= m;
		CBankCustomer::deposit(m);	
		return 1;			
	}		
	void print(){
		cout << "Name: " << CBankCustomer::name << " ID: " << CBankCustomer::id << "\n";
		cout << "Bank balance: " << CBankCustomer::balance << "\n";
		cout << "Internet bank balance: " << balance <<"\n";
	}
};

int main()
{
int t, no_of_days, i;
char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
double money, interest;
char op_code;

//输入测试案例数t
     cin >> t;
     while (t--)
     {
//输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

//输入银行开户用户名,id
        cin >> b_xm >> b_id;

//输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

  CInternetBankCustomer ib_user;

      ib_user.registerUser(i_xm, i_id, i_mm);
      ib_user.openAccount(b_xm, b_id);

      if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
     {
         cout << "Password or ID incorrect" << "\n";
         continue;
      }

//输入天数
      cin >> no_of_days;
      for (i=0; i < no_of_days; i++)
     {
      //输入操作代码, 金额, 当日万元收益
          cin >> op_code >> money >> interest;
          switch (op_code)
         {
            case 'S':  //从银行向互联网金融帐户存入
            case 's':
               if (ib_user.deposit(money) == 0)
               {
                  cout << "Bank balance not enough" << "\n";
                  continue;
               }
               break;
          case 'T':  //从互联网金融转入银行帐户
          case 't':
              if (ib_user.withdraw(money) == 0)
             {
                 cout << "Internet bank balance not enough" << "\n";
                 continue;
             }
             break;
          case 'D':  //直接向银行帐户存款
          case 'd':
               ib_user.CBankCustomer::deposit(money);
              break;
          case 'W':  //直接从银行帐户取款
           case 'w':
               if (ib_user.CBankCustomer::withdraw(money) == 0)
              {
                    cout << "Bank balance not enough" << "\n";
                   continue;
              }
              break;
          default:
                cout << "Illegal input" << "\n";
               continue;
         }
          ib_user.setInterest(interest);
          ib_user.calculateProfit();
//输出用户名,id
//输出银行余额
//输出互联网金融账户余额
          ib_user.print();
          cout << "\n";
      }
   }
}