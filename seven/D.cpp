#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
class cat
{
private:
	char* name;
	int w;
public:
	void get(char* non,int now)
	{
		int len = strlen(non);
		name = new char[len + 1];
		strcpy(name,non);
		w = now;
	}

	int getwei()
	{
		return w;
	}

	char * getname()
	{
		return name;
	}

	void out(cat a)
	{	
		cout << a.name << " ";
	}
};

void cmp(cat& a,cat& b)
{
	cat temp;
	if(a.getwei() > b.getwei())
	{
		temp = a;
		a = b;
		b = temp;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		char name[100];
		int w;
		cat *p;
		p = new cat[n];
		for(int i = 0;i < n;i ++)
		{
			cin >> name >> w;
			p[i].get(name,w);
		}

		for(int i = 0;i < n - 1;i ++)
		{
			for(int j = i + 1;j < n;j ++)
			{
				cmp(p[i],p[j]);
			}
		}

		for(int i = 0;i < n;i ++)p->out(p[i]);
		cout << endl;

		delete p;
	}
	return 0;
}