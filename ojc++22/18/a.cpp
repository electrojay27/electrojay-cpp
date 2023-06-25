#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Member 
{  
protected:
	int id,integral;
	string name;
public:
	Member () {}
	Member (int ID, string na, int I) {
		id = ID;
		name = na;
		integral = I;
	}
	virtual void add(int x) {
		integral += x;
	}
	virtual int exchange(int x) {
		if (x > integral) {
			x = integral;
		}

		integral = integral - x + (x % 100);
		return int(x / 100);
	}
	virtual void print() {
		cout << "普通会员" << id << "--" << name << "--" << integral << "\n";
	}
};

// 贵宾会员类
class VIP:public Member
{  
private:
	int cumulative_ratio,exchange_rate;
public:
	VIP () {}
	VIP (int ID, string na, int I, int c,int e) {
		id = ID;
		name = na;
		integral = I;
		cumulative_ratio = c;
		exchange_rate = e;
	}
	virtual void add(int x) {
		integral += cumulative_ratio * x;
	}
	virtual int exchange(int x) {
		if (x > integral) {
			x = integral;
		}

		integral = integral - x + (x % exchange_rate);
		return int(x / exchange_rate);
	}
	virtual void print() {
		cout << "贵宾会员" << id << "--" << name << "--" << integral << endl;
	}
};

int main()
{
	// 创建一个基类对象指针
	Member* pm;
	// ....其他变量自行编写

	string name;
	int id,integral,exchange_rate,cumulative_ratio,x;

	// 输入数据，创建普通会员对象mm
	cin >> id >> name >> integral;
	Member mm(id,name,integral);

	// 使用指针pm执行以下操作：
	// 1、pm指向普通会员对象mm
	pm = &mm;
	// 2、输入数据，通过pm执行积分累加和积分兑换
	cin >> x;
	pm->add(x);
	cin >> x;
	pm->exchange(x);
	// 3、通过pm调用打印方法输出
	pm->print();

	// 输入数据，创建贵宾会员对象vv
	cin >> id >> name >> integral >> cumulative_ratio >> exchange_rate;
	VIP vv(id,name,integral,cumulative_ratio,exchange_rate);
	// 使用指针pm执行以下操作：
	// 1、pm指向贵宾会员对象vv
	pm = &vv;
	// 2、输入数据，通过pm执行积分累加和积分兑换
	cin >> x;
	pm->add(x);
	cin >> x;
	pm-> exchange(x);
	// 3、通过pm调用打印方法输出
	pm->print();

	return 0;
}