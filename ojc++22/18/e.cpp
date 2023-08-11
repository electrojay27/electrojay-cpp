#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CN; //提前声明
class EN; //提前声明

// 抽象类
class Weight
{
protected:
	char kind[20]; //计重类型
	int gram; // 克
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
	// ....类定义自行编写
private:
	int catty,two,money;
public:
	CN () {}
	CN (int c, int t, int m, int g, const char tk[]) {
		catty = c;
		two = t;
		money = m;
		strcpy(kind, tk);
		gram = g;
	}
	void Convert(int x) {
		catty = x / 500;
		x %= 500;
		two = x / 50;
		x %= 50;
		money = x / 5;
		x %= 5;
		gram = x;
	}
	virtual void print(ostream& out) {
		out << "中国计重:" << catty << "斤" << two << "两" << money << "钱" << gram << "克\n";
	}
};

// 英国计重
class EN : public Weight
{
	// ....类定义自行编写
private:
	int pound,ounce,dram;
public:
	EN () {}
	EN (int p, int o, int d, int g, const char tk[]) {
		pound = p;
		ounce = o;
		dram = d;
		strcpy(kind, tk);
		gram = g;
	}
	void Convert(int x) {
		pound = x / 512;
		x %= 512;
		ounce = x / 32;
		x %= 32;
		dram = x / 2;
		x %= 2;
		gram = x;
	}
	virtual void print(ostream& out) {
		out << "英国计重:" << pound << "磅" << ounce << "盎司" << dram << "打兰" << gram << "克\n";
	}
	operator CN () {
		int x = pound * 512 + ounce * 32 + dram * 2 + gram;
		CN res(x / 500 , x % 500 / 50,x % 50 / 5 ,x % 5,"中国计重");
		return res;
	}
};


// 以全局函数方式重载输出运算符，代码3-5行....自行编写
// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
// 重载函数必须调用参数Weight对象的print方法


ostream& operator<<(ostream& out,Weight & weight)
{
    weight.print(out);
    return out;
}


// 主函数
int main()
{
	int tw;
	// 创建一个中国计重类对象cn
	// 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); // 把输入的克数转成中国计重
	cout << cn;

	// 创建英国计重类对象en
	// 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); // 把输入的克数转成英国计重
	cout << en;
	cn = en; // 把英国计重转成中国计重
	cout << cn;
	return 0;
}