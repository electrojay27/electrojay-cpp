#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

class CDate
{

private:
	int year, month, day;
public:
	CDate(int a, int b, int c){
		year = a;
		month = b;
		day = c;
	}

	int gety(){return year;}
	int getm(){return month;}
	int getd(){return day;}

	bool check(){
		int mon[13] = {0,31,(isLeap() ? 29 : 28),31,30,31,30,31,31,30,31,30,31};

		if(day < 0|| month < 0 || month > 12 || day > mon[month]){
			return false;
		} 

		return true;
	}//检验日期是否合法
	bool isLeap(){
		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	}
	void print(){
		cout << year << "年" << month << "月" << day << "日 ";
	}
};

class COldId
{
protected:
	string pid15,pName; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldId(string pIdVal, string pNameVal, int a,int b,int c) : birthday(a,b,c){
		pid15 = pIdVal;
		pName = pNameVal;

	}
	bool check(); //验证15位身份证是否合法
	void print();
	~COldId(){};
};

class CNewId:public COldId
{
private:
	string pid18;
	CDate issueDay;
	int validYear;
public:
	CNewId(string na,string p15,string p18,int a,int b,int c,int ax,int bx,int cx,int va) : COldId(p15,na,a,b,c), issueDay(ax,bx,cx){
		pid18 = p18;
		validYear = va;
	}
	bool check(){
		char drr[12] = { '1','0','X','9','8','7','6','5','4','3','2','\0' };
		int add[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
		if(pid18.size() == 18){
			string s = pid18;
			for(int i = 0;i < 18;i ++){
				if(i != 18 && s[i] < '0' || s[i] > '9'){return false;}

				if(i == 18 && (s[i] < '0' || s[i] > '9' && s[i] != 'X'))return false;
			}

			string id = s.substr(0,6);
			string sum = s.substr(8,6);
			id = id + sum;
			id = id + s.substr(14,3);
			sum = s.substr(6,8);

			// cout << s << "\n";
			// cout << id << "\n";
			// cout << sum << "\n";

			if(id != pid15){return false;}

			int y = (sum[0] - 48) * 1000 + (sum[1] - 48) * 100 + (sum[2] - 48) * 10 + (sum[3] - 48);
			int m = (sum[4] - 48) * 10 + (sum[5] - 48);
			int d = (sum[6] - 48) * 10 + (sum[7] - 48);

			CDate New(y,m,d);

			int cnt = issueDay.gety() * 10000 + issueDay.getm() * 100 + issueDay.getd();

			cnt += validYear * 10000;

			// if(cnt >= 20211109)cout << "yes3\n"; 

			if(issueDay.check() && New.check() && cnt >= 20211109 && New.gety() == birthday.gety() && New.getm() == birthday.getm() && New.getd() == birthday.getd()){
				int num = 0;
				for(int i = 0;i < 17;i ++){
					num += (s[i] - '0') * add[i];
				}
				num = num % 11;
				if(drr[num] == s[17])return true;
			}
		}
		return false;
	}
	void print(){
		cout << pid18 << " ";
		issueDay.print();
		if(validYear == 100){
			cout << "长期\n";
		}else cout << validYear << "年\n";
	}
};

int main()
{
	int n;
	cin >> n;
	string na,p15,p18;
	int a,b,c,ax,bx,cx,va;
	while(n --){
		cin >> na >> a >> b >> c >> p15 >> p18 >> ax >> bx >> cx >> va;
		CNewId now(na,p15,p18,a,b,c,ax,bx,cx,va);

		cout << na << "\n";

		if(now.check()){
			now.print();
		}else{
			cout << "illegal id\n";
		}
	}	
}