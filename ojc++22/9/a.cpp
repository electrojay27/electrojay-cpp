#include <bits/stdc++.h>
using namespace std;

class CVector
{
private:
	int* date;
	int n;
public:
	CVector(){
		n = 5;
		date = new int[5];
		for(int i = 0;i < 5;i ++){
			date[i] = i;
		}
	};
	CVector(int x,int *a){
		date = a;
		n = x;
	};
	void print()
	{
		for(int i = 0;i < n;i ++){
			cout << date[i] << " \n"[i == n - 1];
		}
	};
	~CVector(){};
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n;i ++)cin >> a[i];

	CVector ord;
	ord.print();
	CVector now(n,a);
	now.print();

	return 0;
}

