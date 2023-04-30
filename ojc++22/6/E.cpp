#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Cstack
{
public:
	Cstack(){
		cout << "Constructor." << endl;
		a = new int[10];
		size = 10;
		top = 0;
	};
	Cstack(int s){
		cout << "Constructor." << endl;
		a = new int[s];
		size = s;
		top = 0;
	}
	int get(int index){
		return *(a + index);
	}
	void push(int n){
		*(a + top) = n;
		top ++;
	}
	int isempty(){
		if(top)return 0;
		else return 1;
	}
	int isfull(){
		if(top == size)return 1;
		else return 0;
	}
	int pop(){
		top --;
		return *(a + top);
	}
	~Cstack(){
		cout << "Destructor." << endl;
		delete[] a;
	}
private:
	int *a;
	int size;
	int top;
};

void solve()
{
	int n,num;
	cin >> n;
	Cstack s(n);
	for(int i = 0;i < n;i ++){
		cin >> num;
		s.push(num);
	}

	for(int i = 0;i < n;i ++){
		if(i)cout << " " << s.pop();
		else cout << s.pop();
	}
	cout << endl;
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