#include <bits/stdc++.h>
using namespace std;

class date
{
	int year,month,day;
public:
	date(){}
	void print()
	{
		cout << year << "." << month << "." << day << "\n";
	}
	void set(int y,int m,int d){
		year = y;
		month = m;
		day = d;
	}
};

class phone
{
private:
	char num_type;
	string number;
	int state;
	date* p = nullptr;
public:
	phone(char ty,string num,int s){
		num_type = ty;
		number = num;
		state = s;
		cout << "Construct a new phone " << number << "\n";
	}
	phone(phone & last){
		cout << "Construct a copy of phone " << last.number << "\n"; 
		num_type = 'D';
		number = last.number + 'X';
		state = last.state;
		p = last.p;
	}
	void stop(int y,int m,int d){
		cout << "Stop the phone " << number << "\n";
		state = 3;
		p = new date;
		p->set(y,m,d);
		cout << "类型=";
		if(num_type == 'A')cout << "机构";
		else if(num_type == 'B')cout << "企业";
		else if(num_type == 'C')cout << "个人";
		else if(num_type == 'D')cout << "备份";
		cout << "||号码=" << number << "||State=";
		if(state == 1)cout << "在用";
		else if(state == 2)cout << "未用";
		else if(state == 3)cout << "停用";
		cout << "||停机日期=";
		p->print();
		cout << "----" << "\n";
	}
	void print(){
		cout << "类型=";
		if(num_type == 'A')cout << "机构";
		else if(num_type == 'B')cout << "企业";
		else if(num_type == 'C')cout << "个人";
		else if(num_type == 'D')cout << "备份";
		cout << "||号码=" << number << "||State=";
		if(state == 1)cout << "在用";
		else if(state == 2)cout << "未用";
		else if(state == 3)cout << "停用";
		cout << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		char ty;
		string num;
		int s,y,m,d;
		cin >> ty >> num >> s >> y >> m >> d;
		phone New(ty,num,s);
		New.print();
		phone now(New);
		now.print();
		New.stop(y,m,d);
	}
	return 0;
}