//题目大意：给一个字符串，然后找出其子字符串中长度为n的不同子字符串，有多少个
//大概思路：题目给了个子字符串不超过16e6，也就是数据范围，然后还有个坑，就是不同字符的数量可能是nc。。。，我人都傻了
//然后就是怎么取字符串，最开始想用map，但是绝对mle，那就只能用一个数组来代替map，但是要思考会不会越界
//于是就要注意进制的选取，所以就有了一开始的可能的nc。。。取n的子字符串，就准备一个头cnt来做减法即可
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
// #define base 26
#define ull unsigned long long

const int maxn = 16e6 + 10;
int n,nc,ans,base;
char a[maxn];
ull Hash;
ull p;
ull cnt;
bool vis[maxn];
int num[26];

void init(){
	p = 1;
	for(int i = 1;i <= n;i ++)p *= base;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> nc){
		// base = nc;//可能出现。。。
		ans = 0;
		cin >> a;
		memset(num,0,sizeof(num));
		memset(vis,false,sizeof(vis));
		int len = strlen(a);

		base = 0;
		for(int i = 0;i < len;i ++){
			if(!num[a[i] - 'a']){
				num[a[i] - 'a'] = base;
				base ++;
			}
			if(base >= nc)break;
		}

		init();

		Hash = cnt = 0;
		for(int i = 0;i < len;i ++){
			Hash = Hash * base + num[a[i] - 'a'];//处理哈希值
			if(i >= n - 1){
				if(!vis[Hash - cnt * p]){
					vis[Hash - cnt * p] = 1;
					ans ++;
				}
				cnt = cnt * base + num[a[i - n + 1] - 'a'];//处理’头‘
			}
		}
		cout << ans << endl;
	}
	return 0;
}