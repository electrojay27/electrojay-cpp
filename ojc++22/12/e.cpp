#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Animal
{
protected:
	string name;
	int old;
public:
	virtual void Seapk() = 0;
};

class tiger:public Animal
{
public:
	tiger(string n,int o){
		name = n;
		old = o;
	}
	virtual void Seapk(){
		cout << "Hello,I am " << name << ",AOOO.\n";
	}
};

class dog:public Animal
{
public:
	dog(string n,int o){
		name = n;
		old = o;
	}
	virtual void Seapk(){
		cout << "Hello,I am " << name << ",WangWang.\n";
	}
};

class duck:public Animal
{
public:
	duck(string n,int o){
		name = n;
		old = o;
	}
	virtual void Seapk(){
		cout << "Hello,I am " << name << ",GAGA.\n";
	}
};

class pig:public Animal
{
public:
	pig(string n,int o){
		name = n;
		old = o;
	}
	virtual void Seapk(){
		cout << "Hello,I am " << name << ",HENGHENG.\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	Animal *p;

	while(t --){
		string A,na;int old;
		cin >> A >> na >> old;
		if(A == "Tiger"){
			p = new tiger(na,old);
		}else if(A == "Pig"){
			p = new pig(na,old);
		}else if(A == "Duck"){
			p = new duck(na,old);
		}else if(A == "Dog"){
			p = new dog(na,old);
		}else{
			cout << "There is no " << A << " in our Zoo.\n";
			continue;
		}

		p->Seapk();
	}

	return 0;
}