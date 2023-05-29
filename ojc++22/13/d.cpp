#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class C1
{
protected:
	int id,j;
public:
	C1 (int i):id(i),j(0){}
};

class C2
{
protected:
	int ID;
	string name;
	int limit;
	float balance;
	int ij;
public:
	C2 (int i,string na,int l):ID(i),name(na),limit(l),ij(0){}
};

class C3:public C1,public C2
{
public:
	C3(int i,int I,string s,int l):C1(i),C2(I,s,l){}
	void tui(float m) {
		if (m <= balance) {
			balance -= m;
			ij -= int(m);
		}
	}
	void mai(float m)
    {
     	j += int(m);
     	ij += int(m);
     	balance += m;
    }
    void consume(float m) {
        if (m + balance <= limit) {
        	balance += m;
        	ij += int(m);
        }
    }
    void exchange(float m) {
    	if (m <= ij) {
    		ij -= int(m);
    		j += int(m) / 2;
    	}
    }
    void display()
    {
        cout << id <<" "<< j << "\n";
        cout << ID <<" "<< name <<" "<< balance <<" "<< ij << "\n";
    }
};

int main() {
	int id,ID,limit,n;
    string name;
    char op;

    cin >> id >> ID >> name >> limit;
    C3 now(id,ID,name,limit);
    cin >> n;
    while (n--) {
    	float m;
    	cin >> op >> m;
    	if (op == 'o') {
    		now.mai(m);
    	} else if (op == 'c') {
    		now.consume(m);
    	} else if (op == 'q') {
    		now.tui(m);
    	} else {
    		now.exchange(m);
    	}
    }
    now.display();
}