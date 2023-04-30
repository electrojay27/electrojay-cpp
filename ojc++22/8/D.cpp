#include <iostream>
#include <cstring>
using namespace std;

class Hotel
{
private:
    static int totalCustNum; // 顾客总人数
    static float totalEarning; // 旅店总收入
    static float rent; // 每个顾客的房租
    char *customerName; // 顾客姓名
    int customerId; // 顾客编号
public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel(char* customer){
    	int len = strlen(customer);
    	customerName = new char[len + 1];
    	for(int i = 0;i < len;i ++){
    		*(customerName + i) = *(customer + i);
    	}
    	*(customerName + len) = '\0';
    	totalCustNum ++;
    	customerId = 20150000 + totalCustNum;
    	totalEarning += rent;

    };
    ~Hotel(){
    	delete customerName;
    };
    void Display(){
    	cout << customerName << " " << customerId << " " << totalCustNum << " " << totalEarning << "\n";
    };
    static void setRent(float x)
    {
    	rent = x;
    };
};

int Hotel :: totalCustNum = 0;
float Hotel :: totalEarning = 0;
float Hotel :: rent = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	float r;
	cin >> r;
	Hotel::setRent(r);
	char a[50];
	while(cin >> a){
		if(a[0] == '0')break;
		Hotel h(a);
		h.Display();
	}

	return 0;
}