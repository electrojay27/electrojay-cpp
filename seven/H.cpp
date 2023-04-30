#include <bits/stdc++.h>
using namespace std;

int flag,ans;
string op[4] = {"白子胜","黑子胜","白子继续","黑子继续"};//状态判断
int d[4][2] = {{1,0},{1,1},{0,1},{1,-1}};
class backgammon
{
private:
	char mp[17][17];//棋盘
public:
	backgammon(){
		memset(mp,'0',sizeof(mp));
	}//清空棋盘
	
	bool judge(int x,int y){
		if(x < 1 || y < 1 || x > 15 || y > 15 || ans != -1 || mp[x][y] != '0')return false;
		return true;
	}//判断棋盘这个位置合不合法

	bool judge_win(int x,int y,char s){
		if(x < 1 || y < 1 || x > 15 || y > 15 || mp[x][y] != s)return false;
		return true;
	}

	void win(int x,int y,char s){
		if(s == 'u')s = '#';
		else s = '@';

		for(int i = 0;i < 4;i ++){
			// if(!dx[i] && !dy[j])continue;
			int xx = x,yy = y;
			int cnt1 = 0;
			int cnt2 = 0;
			while(judge_win(xx + d[i][0],yy + d[i][1],s)){
				xx += d[i][0];
				yy += d[i][1];
				cnt1 ++; 
			}
			xx = x,yy = y;
			while(judge_win(xx - d[i][0],yy - d[i][1],s)){
				xx -= d[i][0];
				yy -= d[i][1];
				cnt2 ++; 
			}
			if(cnt1 + cnt2 >= 4){
				if(s == '#'){
					ans = 1;
					return;
				}else{
					ans = 0;
					return;
				}
			}
		}
	}
	void add(char s,int x,int y){
		if(s == 'u'){
			if(judge(x,y)){
				mp[x][y] = '#';
				flag = 2;
			}
		}else if(s == 'o'){
			if(judge(x,y)){
				mp[x][y] = '@';
				flag = 3;
			}
		}
		if(ans == -1)win(x,y,s);
	}

	void print()
	{
		for(int i = 1;i <= 15;i ++){
			for(int j = 1;j <= 15;j ++){
				cout << mp[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		backgammon five;ans = -1;

		int n,x,y;
		char s;

		cin >> n;

		for(int i = 1;i <= n;i ++){
			cin >> s >> x >> y;
			five.add(s,x,y);
		}

		five.print();
		if(ans != -1)cout << op[ans] << endl;
		else cout << op[flag] << endl;

		cout << endl;
	}
	return 0;
}