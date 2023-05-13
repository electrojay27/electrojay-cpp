#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
	string name;
	int old;
public:
	void display(){};
};

class Lfstudents:public Person
{
private:
	int grade;
	char general;
public:
	Lfstudents(string na,int o,int x){
		name = na;
		old = o;
		grade = x;
	}
	void display(){
		cout << name << ' ' << old << ' ' << general << "\n";
	}
	void js(){
		switch(grade){
			case 85 ... 100 : general = 'A';break;
			case 75 ... 84 : general = 'B';break;
			case 65 ... 74 : general = 'C';break;
			case 60 ... 64 : general = 'D';break;
			case 0 ... 59 : general = 'F';break;
		}
	}
};

class Ne_students:public Person
{
private:
	int a_grade;
	int m_grade;
	int all;
	char general;
public:
	Ne_students(string na,int o,int a,int b){
		name = na;
		old = o;
		a_grade = a;
		m_grade = b;
	}
	void display(){
		cout << name << ' ' << old << ' ' << general << "\n";
	}
	void js(){
		all = (a_grade * 4 + m_grade * 6);
		switch(all){
			case 850 ... 1000 : general = 'A';break;
			case 750 ... 840 : general = 'B';break;
			case 650 ... 740 : general = 'C';break;
			case 600 ... 640 : general = 'D';break;
			case 0 ... 590 : general = 'E';break;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	while(n --){
		char type;
		cin >> type;
		if(type == 'R'){
			string name;
			int old;
			int a,b;
			cin >> name >> old >> a >> b;
			Ne_students now(name,old,a,b); 
			now.js();
			now.display();
		}else{
			string name;
			int old,a;
			cin >> name >> old >> a;
			Lfstudents now(name,old,a);
			now.js();
			now.display();
		}
	}

	return 0;
}