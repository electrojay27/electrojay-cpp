#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
class cat
{
private:
	char* name;
	double h,m,y;
public:
	void get(char* non,double nom,double noh,double noy)
	{
		int len = strlen(non);
		name = new char[len + 1];
		strcpy(name,non);
		m = nom;
		h = noh;
		y = noy;
		// cin >> name >> h >> m >> y;
	}

	void BMI(){
		cout<< name << "的BMI指数为" << fixed << setprecision(0) << m * 1.0 / (h * h) << "--";
	}

	void tzl()
	{
		double ans;
		double a = y * 0.74;
		double b = m * 0.082 + 34.89;
		ans = (a - b) / m;
		cout << "体脂率为" << fixed << setprecision(2) << ans << endl;
	}

};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		char name[100];
		int m,h,y;
		cat *p;
		p = new cat[n];
		for(int i = 0;i < n;i ++)
		{	
			cin >> name >> h >> m >> y;
			p[i].get(name,m,h,y);

			p[i].BMI();
			p[i].tzl();
		}
		delete p;
	}
	return 0;
}