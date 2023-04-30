#include <bits/stdc++.h>
using namespace std;

class construct
{
private:
	int x;
public:
	construct()
	{
		x = 0;
		cout << "Constructed by default, value = " << x << "\n";
	}
	construct(int n)
	{
		x = n;
		cout << "Constructed using one argument constructor, value = " << x << "\n";
	}
	construct(construct & last){
		x = last.x;
		cout << "Constructed using copy constructor, value = " << x << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		int n,x;
		cin >> n;
		if(!n){
			construct c;
		}else if(n == 1){
			cin >> x;
			construct c(x);
		}else{
			cin >> x;
			construct c(x);
			construct last(c);
		}
	}
	return 0;
}