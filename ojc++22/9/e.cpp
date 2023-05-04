#include <bits/stdc++.h>
using namespace std;

class CMatrix;

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
			// sum += date[i];
		}
	};
	CVector(int x){
		n = x;
		date = new int[n];
		for(int i = 0;i < n;i ++){
			date[i] = 0;
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
	float Average(){
		return 1.0 * sum / n;
	}
	friend class CMatrix;
};

int CVector::sum = 0;

CVector add(const CVector v1, const CVector v2){
	CVector ans(v1.n);
	for(int i = 0;i < v2.n;i ++){
		ans.date[i] += v2.date[i];
	}
	return ans;
}

class CMatrix
{
private:
	int n;
	int ** date;
public:
	CMatrix(){};
	CMatrix(int x,int **a){
		// cout << "Yes\n";
		n = x;
		date = new int*[n];
		for(int i = 0;i < n;i ++)date[i] = new int[n];

		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				date[i][j] = a[i][j];
	}
	CVector multi(const CVector &v1){
		CVector ans(v1.n);
		for(int i = 0;i < v1.n;i ++)
			for(int j = 0;j < v1.n;j ++)
				ans.date[i] += v1.date[j] * date[i][j];

		return ans;
	}

	bool mul(int m,int n){
        if(m == n)return true;
        return false;
    }

    ~CMatrix(){
    	for(int i = 0; i < n;i++){
			delete [] date[i];
		}
		delete [] date;

    };
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		int n,m;
		cin >> n;
		int ** a;
		a = new int*[n];
		for(int i = 0;i < n;i ++)a[i] = new int[n];
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				cin >> a[i][j];

		CMatrix _n(n,a);

		cin >> m;
		int* b;
		b = new int[m];
		for(int i = 0;i < m;i ++)cin >> b[i];

		CVector _m(m,b);

		if(_n.mul(n,m)){
			_n.multi(_m).print();
		}else{
			cout << "error\n";
		}

		for(int i = 0; i < n;i++){
			delete [] a[i];
		}
		delete [] a;
		delete [] b;
	}

	return 0;
}