#include <bits/stdc++.h>
using namespace std;

char a[10];
int num;
int cnt;
int mon[13] = {29,31,28,31,30,31,30,31,31,30,31,30,31};

void to(int sum,char op[]){
	for(int i = 7;i >= 0;i --){
		op[i] = sum % 10 + '0';
		sum /= 10;
	}
}

bool judge1(char op[]){//判断是否回文
	for(int i = 0;i < 4;i ++){
		if(op[i] != op[7-i])return false;
	}
	return true;
}

bool judge2(int sum){//判断是否合法
	int y = sum / 10000;
	int m = sum % 10000 / 100;
	int d = sum % 100;
	if(m <= 0 || m > 12 || d > 31 || d <= 0)return false;

	if(m != 2){
		if(d > mon[m])return false;
	}else if((!(y % 4) && (y % 100)) || !(y % 400)){
		if(d > mon[0])return false;
	}else{
		if(d > mon[2])return false;
	}
	return true;
}

bool judge3(char op[]){
	if(op[0] == op[2] && op[1] == op[3])return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> num){
		cnt = 0;
		char op[10];
		to(num,op);
		if(judge1(op) && judge2(num))num ++,to(num,op);
		while(!judge1(op) || !judge2(num)){
			if(num % 100 > 31){
				num /= 100;
				num ++;
				num *= 100;
				num ++;
			}else if(num % 10000 / 100 > 12){
				int d = num % 100;
				num /= 10000;
				num ++;
				num *= 100;
				num ++;
				num *= 100;
				num += d;
			}else num ++;
			to(num,op);
		}
		cout << num << endl;
		if(judge3(op))cout << num << endl,cnt = 1;

		if(!cnt){
			while(!judge1(op) || !judge2(num) || !judge3(op)){
				num ++;
				to(num,op);
			}
			cout << num << endl;
		}
	}
	return 0;
}