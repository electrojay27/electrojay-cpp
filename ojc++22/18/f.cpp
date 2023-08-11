#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int hmax = 26;
class Info { //联系人，用一个链表结点表示
	string name; //姓名
	int phoneNo; //电话
public:
	Info* next;  //指向下一个结点
	Info(string tn = "no name", int pno = 0)
	{
		name = tn;
		phoneNo = pno;
		next = NULL;
	}
	void Print()
	{
		cout << name << "--" << phoneNo << endl;
	}
	string getname() {
		return name;
	}
	int getphone() {
		return phoneNo;
	}
	void setname(string na) {
		name = na;
	}
	void setphone(int ph) {
		phoneNo = ph;
	}
	//属性的get和set方法....自行定义
};

class PhoneBook {//组链表方式实现通讯录
 //....自行增加一些操作
 //提示：把插入和查找先写成内部函数，再被运算符重载调用，会更方便
public:
	Info Table[hmax]; //链表头结点数组，对应26个大写字母
	//以下定义五个操作：输入Input、打印Print、插入、合并、查找
	//具体操作看前面说明
	void Input() {
		for (int i = 0; i < hmax; i++) {
			Table[i] = Info();
		}
		int t;
		cin >> t;
		while (t--) {
			string na;
			int ph;
			cin >> na >> ph;
			Info* now;
			now = new Info(na,ph);
			now->next = Table[na[0] - 'A'].next;
			Table[na[0] - 'A'].next = now;
		}
	}

	Info* find(string na) {
		Info* res;
		res = Table[na[0] - 'A'].next;
		while (res != NULL) {
			if (res->getname() == na) {
				return res;
			}
			res = res->next;
		}
		return res;
	}
	Info* operator() (string na) {
		return find(na);
	}
	PhoneBook add(Info &r){
        Info *res = find(r.getname());
        if(res){
            res->setphone(r.getphone());
        }
        else{
            string now = r.getname();
            r.next = Table[now[0] - 'A'].next;
            Table[now[0] - 'A'].next = &r;
        }
        return *this;
    }
    PhoneBook operator+=(Info &r){
        return add(r);
    }
    PhoneBook operator + (PhoneBook& a){
        for (int i = 0; i < hmax; i++) {
        	if (a.Table[i].next) {
        		Info *res = a.Table[i].next;
        		while (res) {
        			Info* ret = find(res->getname());
        			if (ret) {
        				ret->setphone(res->getphone());
        			} else {
        				ret = new Info(res->getname(),res->getphone());
        				add(*ret);
        			}
        			res = res->next;
        		}
        	}
        }
        return *this;
    }
    void Print() {
    	for(int i = 0; i < hmax; i++){
            if(Table[i].next){
                Info *res = Table[i].next;
                cout << res->getname()[0] << "--";
                while (res) {
                    cout << res->getname() << "." << res->getphone() << "--";
                    res = res->next;
                }
                cout << "\n";
            }
        }
    }
};
//...PhoneBook类成员函数，类外实现，自行编写


//----主函数----
int main()
{
	string tname;
	int i, tno;
	Info* p;

	PhoneBook pb;
	pb.Input(); //接收输入数据，初始化第一个通讯录
	//两次姓名查找
	for (i = 0; i < 2; i++)
	{
		cin >> tname;
		p = pb(tname); //调用()运算符，实现查找
		if (p) p->Print(); //查找成功，输出联系人信息
		else cout << "查找失败" << endl; //查找失败，输出提示信息
	}
	//一次插入
	cin >> tname >> tno;
	Info temp(tname, tno);
	pb += temp; //调用+=运算符，实现插入新联系人

	//通讯录合并
	PhoneBook pc;
	pc.Input(); //初始化第二个通讯录
	pb = pb + pc; //调用+运算符，实现合并

	pb.Print(); //输出所有操作后的通讯录

	return 0;
}