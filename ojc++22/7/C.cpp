#include <bits/stdc++.h>
using namespace std;

class CTelNumber
{
private:
	char* num;
	int flag;
public:
	// CTelNumber(){
	// 	num = new char[7];
	// }
	CTelNumber(char a[]){
		num = new char[8];
		for(int i = 0;i < 7;i ++){
			*(num + i) = a[i];
		}
	}
	~CTelNumber(){
		delete[] num;
	}
	CTelNumber(const CTelNumber & last){
		flag = 0;
		num = new char[9];
		if(last.num[0] == '2' || last.num[0] == '3' || last.num[0] == '4'){
			*num = '8';
			for(int i = 0;i < 8;i ++){
				*(num + i + 1) = *(last.num + i);
			}
		}else if(last.num[0] == '6' || last.num[0] == '7' || last.num[0] == '8' || last.num[0] == '5'){
			*num = '2';
			for(int i = 0;i < 8;i ++){
				*(num + i + 1) = *(last.num + i);
			}
		}else{
			flag = 1;
		}
	}
	void print()
	{
		if(!flag)cout << num << "\n";
		else cout << "Illegal phone number\n";
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		char a[8];
		cin >> a;
		// cout << a << endl;
		if(strlen(a) != 7)cout << "Illegal phone number\n";
		else{
			int flag = 0;
			for(int i = 0;i < 7;i ++){
				if(a[i] < '0' || a[i] > '9'){
					cout << "Illegal phone number\n";
					flag = 1;
					break;
				}
			}
			if(!flag){
				CTelNumber New(a);
				CTelNumber again(New);
				again.print();
			}
		}
	}
	return 0;
}