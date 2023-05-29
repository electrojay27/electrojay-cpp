#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CPeople
{
protected:
	string name;
	char type;
	int year;
public:
	CPeople (string n,char t,int y) {
		name = n;
		type = t;
		year = y;
	}
	CPeople (CPeople& a) {
		name = a.name;
		type = a.type;
		year = a.year;
	}
	virtual void print() {
		cout << "People:\n";
		cout << "Name: " << name << "\n";
		cout << "Sex: " << type << "\n";
		cout << "Age: " << year << "\n";
		cout << "\n";
	}
};

class CStudent:public CPeople
{
protected:
	int id;
	double grade;
public:
	CStudent (CPeople& a,int d,double g) : CPeople(a) {
		id = d;
		grade = g;
	}
	virtual void print() {
		cout << "Student:\n";
		cout << "Name: " << name << "\n";
		cout << "Sex: " << type << "\n";
		cout << "Age: " << year << "\n";
		cout << "No.: " << id << "\n";
		cout << "Score: " << grade << "\n";
		cout << "\n";
	}
};

class CTeacher:public CPeople
{
protected:
	string Position,Department;
public:
	CTeacher (CPeople& a,string p,string d) : CPeople(a) {
		Position = p;
		Department = d;
	}
	virtual void print() {
		cout << "Teacher:\n";
		cout << "Name: " << name << "\n";
		cout << "Sex: " << type << "\n";
		cout << "Age: " << year << "\n";
		cout << "Position: " << Position << "\n";
		cout << "Department: " << Department << "\n";
		cout << "\n";
	}
};

class CGradOnWork:public CStudent,public CTeacher
{
private:
	string Direction,Tutor;
public:
	CGradOnWork (CPeople& a,int i,double g,string D,string p,string d,string t):CStudent(a,i,g),CTeacher(a,p,D){
		Direction = d;
		Tutor = t;
	}
	virtual void print() {
		cout << "GradOnWork:\n";
		cout << "Name: " << CStudent::name << "\n";
		cout << "Sex: " << CStudent::type << "\n";
		cout << "Age: " << CStudent::year << "\n";
		cout << "No.: " << id << "\n";
		cout << "Score: " << grade << "\n";
		cout << "Position: " << Position << "\n";
		cout << "Department: " << Department << "\n";
		cout << "Direction: " << Direction << "\n";
		cout << "Tutor: " << Tutor << "\n";
		cout << "\n";
	}
};

int main() {
	string name,p,d,D,t;
	int id,y;
	double g;
	char type;
	cin >> name >> type >> y;
	CPeople a(name,type,y);
	a.print();
	cin >> id >> g;
	CStudent b(a,id,g);
	b.print();
	cin >> p >> d;
	CTeacher c(a,p,d);
	c.print();
	cin >> D >> t;
	CGradOnWork e(a,id,g,d,p,D,t);
	e.print();
}