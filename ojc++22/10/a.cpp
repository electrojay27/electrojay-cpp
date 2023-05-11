#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Robot
{
private:
	static int sum;
	string Name;
	char type;
	int level;
	int attack;
	int defense;
	int life;
public:
	Robot(){};
	Robot(string Na,char ty,int le){
		Name = Na;
		type = ty;
		level = le;
		attack = le * 5;
		defense = le * 5;
		life = le * 5;
		if(type == 'A'){
			attack = le * 10;
		}else if(type == 'D'){
			defense = le * 10;
		}else if(type == 'H'){
			life = le * 50;
		}
	}
	bool transform(char x){
		if(type == x){
			return false;
		}else{
			attack = level * 5;
			defense = level * 5;
			life = level * 5;
			if(x == 'A'){
				attack = level * 10;
			}else if(x == 'D'){
				defense = level * 10;
			}else if(x == 'H'){
				life = level * 50;
			}
			type = x;
			return true;
		}
	}
	void print(){
		cout << Name << "--";
		cout << type << "--";
		cout << level << "--";
		cout << life << "--";
		cout << attack << "--";
		cout << defense << "\n";
	}
	void addsum(char x){
		if(transform(x)){
			sum ++;
		}
	}
	void Print(){
		cout << "The number of robot transform is " << sum << "\n";
	}
};

int Robot::sum = 0;

void solve(int x)
{
	string name;
	char type;
	int level;
	cin >> name >> type >> level;

	Robot now(name,type,level);

	cin >> type;

	now.addsum(type);

	now.print();

	if(!x)now.Print();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve(t);
	}
	return 0;
}