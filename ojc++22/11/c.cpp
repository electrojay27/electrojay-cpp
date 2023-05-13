#include <bits/stdc++.h>
#define pi 3.14
using namespace std;

using i64 = long long;

class counter
{
protected:
	int value;
public:
	int increment(){
		value ++;
		return value;
	}
};

class cycle_calculator:public counter
{
protected:
	int minValue,maxValue;
public:
	cycle_calculator(){};
	cycle_calculator(int a,int b,int c){value = a;minValue = b;maxValue = c;}
	int increment(){
		if(++value >= maxValue){
			value -= (maxValue - minValue);
		}
		return value;
	}
	int get()
	{
		return value;
	}
};

class Big_Ben
{
private:
	cycle_calculator hour,mintue,second;
public:
	Big_Ben(int a,int b,int c):hour(a,0,24),mintue(b,0,60),second(c,0,60){}
	void calculating(int s){
		while(s --){
			if(second.increment() == 0)
				if(mintue.increment() == 0)
					hour.increment();
		}
		cout << hour.get() << ':' << mintue.get() << ':' << second.get() << "\n";
	}
};

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while(n --){
		int a,b,c,s;
		cin >> a >> b >> c >> s;

		Big_Ben now(a,b,c);
		now.calculating(s);
	}

	return 0;
}