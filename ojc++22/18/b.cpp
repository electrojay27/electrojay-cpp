#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Metal
{
private:
	int hardness,weight,volume;
public:
	Metal () {}
	Metal (int h, int w, int v) {
		hardness = h;
		weight = w;
		volume = v;
	}
	Metal (const Metal& a) {
		this->hardness = a.hardness;
		this->weight = a.weight;
		this->volume = a.volume;
	}
	friend Metal operator + (const Metal& a,const Metal& b) {
		Metal res(0,0,0);

		res.hardness = b.hardness + a.hardness;
		res.weight = b.weight + a.weight;
		res.volume = b.volume + a.volume;

		return res;
	}
	friend Metal operator * (const Metal& a,int x) {
		Metal res;

		res.hardness = a.hardness;
		res.weight = a.weight;
		res.volume = x * a.volume;

		return res;
	}
	Metal operator ++ () {
		this->hardness ++;
		this->weight += this->weight / 10;
		this->volume += this->volume / 10;
		return *this;
	}
	Metal operator -- (int) {
		Metal res(*this);
		this->hardness --;
		this->weight -= this->weight / 10;
		this->volume -= this->volume / 10;
		return res;
	}
	void print() {
		cout << "硬度" << hardness << "--" << "重量" << weight << "--" << "体积" << volume << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b,c;
	cin >> a >> b >> c;
	Metal A(a,b,c);
	cin >> a >> b >> c;
	Metal B(a,b,c);
	int n;
	cin >> n;

	Metal C = A + B;
	C.print();
	C = A * n;
	C.print();
	++A;
	A.print();
	B--;
	B.print();
}