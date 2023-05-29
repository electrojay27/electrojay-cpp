#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Student{
protected:
 	string name; //学生姓名
 	int type; //学生类别:1表示本科生，2表示研究生
 	int courses[3]; //3门课的成绩
 	string courseGrade; //成绩等级
public:
 	Student(string n,int t,int a1,int a2,int a3) {
 		name = n;
 		type = t;
 		courses[0] = a1;
 		courses[1] = a2;
 		courses[2] = a3;
 	}
 	virtual void calculateGrade()=0;//计算成绩等级
 	void print() {
 		cout << name;
 		if (type == 1) {
 			cout << ",本科生,";
 		} else {
 			cout << ",研究生,";
 		}
 		cout << courseGrade << "\n";
 	}
};

class Postgraduate:public Student{
public:
	Postgraduate(string n,int t,int a1,int a2,int a3):Student(n,t,a1,a2,a3){}
	virtual void calculateGrade() {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += courses[i];
		}
		switch (sum) {
			case 270 ... 300:courseGrade = "优秀";break;
			case 240 ... 269:courseGrade = "良好";break;
			case 210 ... 239:courseGrade = "一般";break;
			case 180 ... 209:courseGrade = "及格";break;
			case 0 ... 179:courseGrade = "不及格";break;
		}
	}
};

class Undergraduate:public Student{
public:
	Undergraduate(string n,int t,int a1,int a2,int a3):Student(n,t,a1,a2,a3){}
	virtual void calculateGrade() {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += courses[i];
		}
		switch (sum) {
			case 240 ... 300:courseGrade = "优秀";break;
			case 210 ... 239:courseGrade = "良好";break;
			case 180 ... 209:courseGrade = "一般";break;
			case 150 ... 179:courseGrade = "及格";break;
			case 0 ... 149:courseGrade = "不及格";break;
		}
	}
};

int main() {
	int n;
	cin >> n;
	Student* p;
	while (n--) {
		string name;
		int t,a,b,c;
		cin >> name >> t >> a >> b >> c;
		if (t == 1) {
			p = new Undergraduate(name,t,a,b,c);
		} else {
			p = new Postgraduate(name,t,a,b,c);
		}

		p->calculateGrade();
		p->print();
	}
}