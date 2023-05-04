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
	CVector(const CVector &v){
		n = v.n;
		date = new int [n];
		for(int i = 0;i < n;i ++){
			date[i] = v.date[i];
		}
	}
	CVector(int x,int *a){
		n = x;
		date = new int[n];
		for(int i = 0;i < n;i ++){
			date[i] = a[i];
		}
	};
	void print()
	{
		for(int i = 0;i < n;i ++){
			cout << date[i] << " \n"[i == n - 1];
		}
	};
	~CVector(){
		delete[] date;
	};
	friend CVector add(const CVector v1, const CVector v2);
};

CVector add(const CVector v1, const CVector v2){
	CVector ans(v1.n,v1.date);
	for(int i = 0;i < v2.n;i ++){
		ans.date[i] += v2.date[i];
	}
	return ans;
}

void solve()
{
	int n;
	cin >> n;

	int a[n],b[n];
	for(int i = 0;i < n;i ++)cin >> a[i];
	for(int i = 0;i < n;i ++)cin >> b[i];
	
	CVector v1(n,a);
	CVector v2(n,b);

	v1.print();
	v2.print();
	add(v1,v2).print();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve();
	}

	return 0;
}