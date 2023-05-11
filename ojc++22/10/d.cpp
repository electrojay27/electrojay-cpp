#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class TV
{
private:
	int model;
	int channel;
	int volume;
	int id;
	static int tv;
	static int dvd;
public:
	TV(){};
	static void settv(int x){
		tv += x;
	}
	static void setdvd(int x){
		dvd += x;
	}
	static int gettv(){return tv;}
	static int getdvd(){return dvd;}
	void initialization(int x){
		model = 1;
		channel = x + 1;
		volume = 50;
		id = x + 1;
	}
	void print(){
		cout << "第" << id << "号电视机--";
		if(model == 1){
			cout << "TV模式--";
		}else cout << "DVD模式--";

		cout << "频道" << channel << "--";
		cout << "音量" << volume << "\n";
	}
	friend void remote(TV &a,int mod,int change_vol,int chan);
};

int TV::tv = 0;
int TV::dvd = 0;

void remote(TV &a,int mo,int chan,int change_vol){
	if(a.model != mo){
		if(mo == 1){
			TV::settv(1);
			TV::setdvd(-1);
		}else TV::settv(-1),TV::setdvd(1);
	}

	a.model = mo;

	a.volume += change_vol;
	if(a.volume > 100)a.volume = 100;
	if(a.volume < 0)a.volume = 0;

	a.channel = chan;

	a.print();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	TV* m = new TV[n];
	for(int i = 0;i < n;i ++){
		m[i].initialization(i);
	}
	TV::settv(n);

	int t;
	cin >> t;
	int id,model,channel,volume;
	for(int i = 0;i < t;i ++){
		cin >> id >> model >> channel >> volume;
		remote(m[id - 1],model,channel,volume);
	}

	cout << "播放电视的电视机数量为" << TV::gettv() << "\n";
	cout << "播放DVD的电视机数量为" << TV::getdvd() << "\n";

	delete[] m;

	return 0;
}