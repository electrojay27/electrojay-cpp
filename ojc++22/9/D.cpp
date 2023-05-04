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
			cout << date[i] << " \n"[i == n];
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
};

int CVector::sum = 0;

CVector add(const CVector v1, const CVector v2){
	CVector ans(v1.n,v1.date);
	for(int i = 0;i < v2.n;i ++){
		ans.date[i] += v2.date[i];
	}
	return ans;
}

class CStudent
{
private:
	string name;
	CVector score;
public:
	CStudent(string na,int x,int *a):score(x,a){
		name = na;
	}
	void print(){
		cout << name << " ";
		score.print();
		cout << fixed << setprecision(2) << score.Average() << endl;
		score.fresh();
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string name;
	int n = 2;
	while(n--){
		cin >> name;
		int n;
		cin >> n;
		int a[n];
		for(int i = 0;i < n;i ++){
			cin >> a[i];
		}

		CStudent now(name,n,a);
		now.print();
	}

	return 0;
}