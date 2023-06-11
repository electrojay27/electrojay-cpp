#include <iostream>
#include <string>
using namespace std;
class CXGraph
{
	int num;
public:
	CXGraph(int num):num(num) {  }
	friend ostream& operator<<(ostream& out,CXGraph x);
	CXGraph& operator++()
	{
		if (num <= 19)
		{
			num++;
			num++;
		}
		return *this;
	}
	CXGraph operator++(int)
	{
		CXGraph temp=*this;
		if (num <= 19)
		{
			num++;
			num++;
		}
		return temp;
	}
	CXGraph& operator--()
	{
		if (num >= 3)
		{
			num--;
			num--;
		}
		return *this;
	}
	CXGraph operator--(int)
	{
		CXGraph temp=*this;
		if (num >= 3)
		{
			num--;
			num--;
		}
		return temp;
	}
	void show()
	{
		int i, j;
		for (i = 0; i <num/2; i++)
		{
			for (j = 0; j < num; j++)
				if (j<num - i && j>=i)
					cout << 'X';
				else if(j<num-i)
					cout << ' ';
			cout << endl;
		}
		for (i = num / 2; i >=0 ; i--)
		{
			for (j = 0; j < num; j++)
				if (j < num - i && j >= i)
					cout << 'X';
				else if(j<num-i)
					cout << ' ';
			cout << endl;
		}
	}
};
ostream& operator<<(ostream& out,CXGraph x)
{
	x.show();
	return out;
}
int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if(command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }
    }
    return 0;
}