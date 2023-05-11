#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class phonenumber
{
private:
	int number;
	char type;
public:
	phonenumber(){};
	phonenumber(int num,char ty){
		number = num;
		type = ty;
	}
	int getnumber(){
		return number;
	}
	char gettype(){
		return type;
	}
};

class virtual_phone
{
private:
	phonenumber phone;
	int state;
	string name;
public:
	virtual_phone(){};
	virtual_phone(int num,char type,int st,string na) : phone(num,type){
		state = st;
		name = na;
		cout << phone.getnumber() << " constructed.\n";
	}
	~virtual_phone(){
		cout << phone.getnumber() << " destructed.\n";
	}
	void print(){
		cout << "Phone="<< phone.getnumber() << "--";
		cout << "Type=" << phone.gettype() << "--";
		cout << "State=" << (state == 1 ? "use" : "unuse") << "--";
		cout << "Owner=" << name << "\n";
	}
	bool Find(int x){
		if(phone.getnumber() != x){
			return false;
		}
		return true;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string name;
	char type;
	int state;
	int number;

	cin >> number >> type >> state >> name;
	virtual_phone a(number,type,state,name);
	cin >> number >> type >> state >> name;
	virtual_phone b(number,type,state,name);
	cin >> number >> type >> state >> name;
	virtual_phone c(number,type,state,name);

	int t;
	cin >> t;
	while(t --){
		cin >> number;
		if(a.Find(number)){
			a.print();
		}else if(b.Find(number)){
			b.print();
		}else if(c.Find(number)){
			c.print();
		}else{
			cout << "wrong number.\n";
		}
	}

	return 0;
}