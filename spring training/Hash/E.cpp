//题目大意：有两个字符串，寻找彼此前后缀对应相同的最长长度，一个字符串的前缀对应另一个的后缀
//大概思路:也就是建立两个hash数组，然后进行枚举，，对应每个字母，比较hash值是否相等即可
//大概的时间复杂度是O(5n),当然这道题的数据比较小，所以不会潮时，也不会mlt，对于空间复杂度的优化，还可以用即时计算hash值来优化
//也就是滚动数组，与此同时时间也会上升
#include <bits/stdc++.h>
using namespace std;
#define base 107
#define ull unsigned long long

ull Hash[2][100];
ull p[100];
char a[100],b[100];
// int vis[100];
int ans;

void init(){
	p[0] = 1;
	for(int i = 1;i < 100;i ++)p[i] = p[i-1] * base;
}

void HASH(char x[],int op){
	Hash[op][0] = x[0] - 'a' + 1;
	for(int i = 1;i < strlen(x);i ++)Hash[op][i] = Hash[op][i - 1] * base + x[i] - 'a' + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	cin >> a;
	cin >> b;
	ans = 0;
	HASH(a,0);
	HASH(b,1);
	// memset(vis,0,sizeof(vis));
	int lena = strlen(a);
	int lenb = strlen(b);
	for(int l = 0;l < lena;l ++){
		for(int r = lenb - 1;r >= 0;r --){
			if(b[r] == a[0]){
				if(lenb - r > l + 1){
					l = lenb - r - 2;
					break;
				}else{
					if(Hash[0][l] == Hash[1][lenb - 1] - Hash[1][r - 1] * p[l + 1]){
						ans = max(ans,l + 1);
					}
				}
			}
		}
	}//后缀
	for(int l = 0;l < lenb;l ++){
		for(int r = lena - 1;r >= 0;r --){
			if(a[r] == b[0]){
				if(lena - r > l + 1){
					l = lena - r - 2;
					break;
				}else{
					if(Hash[1][l] == Hash[0][lena - 1] - Hash[0][r - 1] * p[l + 1]){
						ans = max(ans,l + 1);
					}
				}
			}
		}
	}//前缀
	cout << ans << endl;
	return 0;
}