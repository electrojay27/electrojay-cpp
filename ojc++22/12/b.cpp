#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Vehicle
{ 
protected:
     string no; //编号
public:
    virtual void display()=0; //应收费用
};

class Car:public Vehicle
{
private:
	int x,y;
public:
	Car(string n,int xx,int yy){no = n,x = xx,y = yy;}
	virtual void display(){
		cout << no << " " << x * 8 + y * 2 << "\n";
	}
};

class Truck:public Vehicle
{
private:
	int x;
public:
	Truck(string n,int xx){no = n,x = xx;}
	virtual void display(){
		cout << no << " " << x * 5 << "\n";
	}
};

class Bus:public Vehicle
{
private:
	int y;
public:
	Bus(string n,int yy){no = n,y = yy;}
	virtual void display(){
		cout << no << " " << y * 30 << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	Vehicle *p;
	while(t --){
		int n;
		cin >> n;
		string no;
		int x,y;
		if(n == 1){
			cin >> no >> x >> y;
			p = new Car(no,x,y);
			// p->display();
		}else if(n == 2){
			cin >> no >> x;
			p = new Truck(no,x);
			// p->display();
		}else{
			cin >> no >> y;
			p = new Bus(no,y);
			// p->display();
		}
		p->display();
	}

	return 0;
}