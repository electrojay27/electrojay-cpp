#include <bits/stdc++.h>
using namespace std;

class CVector
{
private:
	static int sum;
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
			sum += date[i];
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
	void fresh()
	{
		sum = 0;
	}
	static int print_sum()
    {
        return sum;
    }
	friend CVector add(const CVector v1, const CVector v2);
};

int CVector::sum = 0;

CVector add(const CVector v1, const CVector v2){
	CVector ans(v1.n,v1.date);
	for(int i = 0;i < v2.n;i ++){
		ans.date[i] += v2.date[i];
	}
	return ans;
}

void solve()
{
	int m;
	cin >> m;

	for(int i = 0;i < m;i ++){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0;i < n;i ++)cin >> a[i];
		CVector v(n,a);
		v.print();

		if(i == m - 1){
			cout << v.print_sum() << "\n";
			v.fresh();
		}
	}
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