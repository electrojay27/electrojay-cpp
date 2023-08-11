#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class home_appliances
{
protected:
	int id,power;
public:
	home_appliances () {}
	home_appliances (int ID, int p) {
		id = ID;
		power = p;
	}
	virtual void print() = 0;
};

class electric_fan:virtual public home_appliances
{
protected:
	int wind_direction,wind_power;
public:
	electric_fan () {}
	electric_fan (int i, int p, int wd, int wp) : home_appliances(i,p) {
		wind_direction = wd;
		wind_power = wp;
	}
	virtual void wind_direction_control (int x) {
		wind_direction = x;
	}
	virtual void wind_control (int x) {
		wind_power = x;
	}
	virtual void print() = 0;
};

class humidifier:virtual public home_appliances
{
protected:
	double actual_water_capacity,water_capacity;
public:
	humidifier () {}
	humidifier (int i, int p, double awc, double wc) : home_appliances(i,p) {
		actual_water_capacity = awc;
		water_capacity = wc;
	}
	virtual int early_warning () {
		int res = actual_water_capacity / water_capacity * 100;
		if (res >= 50) return 1;
		else if (res >= 10) return 2;
		else return 3;
	}
	virtual void print () = 0;
};

class humidification_fan:public electric_fan,public humidifier
{
protected:
	int gear;
public:
	humidification_fan () {}
	humidification_fan (int i, int p, int wd, int wp, double awc, double wc,int g){
		id = i;
		power = p;
		wind_direction = wd;
		wind_power = wp;
		actual_water_capacity = awc;
		water_capacity = wc;
		gear = g;
	}
	void Adjust_gear (int x) {
		gear = x;
		if (x) {
			if (x == 1) {
				electric_fan::wind_direction_control(0);
			} else {
				electric_fan::wind_direction_control(1);
			}
			electric_fan::wind_control(x);
		}
	}
	virtual void print() {
		cout << "加湿风扇--档位" << gear << "\n";

		cout << "编号" << home_appliances::id << "--功率" << home_appliances::power << "W\n";

		if (electric_fan::wind_direction) {
			cout << "旋转吹风--"; 
		} else {
			cout << "定向吹风--";
		}

		cout << "风力" << electric_fan::wind_power << "级\n";

		cout << "实际水容量" << humidifier::actual_water_capacity << "升--";

		int res = humidifier::early_warning();

		if (res == 1) {
			cout << "水量正常\n";
		} else if (res == 2) {
			cout << "水量偏低\n";
		} else {
			cout << "水量不足\n";
		}

	}
};

void solve() {
	int i,p,wd,wp,awc,wc,g;
	cin >> i >> p >> wd >> wp >> awc >> wc >> g;
	humidification_fan now(i,p,wd,wp,awc,wc,g);

	int x;
	cin >> x;
	now.Adjust_gear(x);
	now.print();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}