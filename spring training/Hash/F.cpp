//题目大意：将n个单词合并，前后缀相同的合并在一起，输出最后的字符串
//思路：这道题，折磨人啊TAT，首先就是去找前后缀，利用hash来证明是否相等，用ull来储存，防止越界，前期一直wa第65组数据，我人都傻了，怎么调进制和mod都没用（看别人的博客发现2333333和999999998好像可以）
//这个时候说明单哈希就不可以了，转用双哈希，也就是多加一层罢了，什么，MLE，o(TヘTo)，我去，数组用太多了，那就得消去，怎么消，其实我们只需要对比前后缀即可
//那么我们可以直接滚动数组，减少两个大数组的开销，在滚动中进行判断，但是怎么算后缀呢，就相当于反过来算，原本进制是算总体，现在不是，是算前面的，问题解决！

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e6 + 10;
int n,flag,cmp;
string ans;
// char ans[maxn];
string op;
// char op[maxn];
ll base[2] = {2333333,131};
ll mod[2] = {999999998,1000000007};
ll H[2];//总字符串哈希值
ll h[2];//子字符串哈希值
ll p[2][maxn];

void init(){
	p[0][0] = p[1][0] = 1;
	for(int i = 1;i < maxn;i ++){
		for(int j = 0;j < 2;j ++){
			p[j][i] = (p[j][i - 1] * base[j]) % mod[j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	while(cin >> n){
		cin >> ans;
		// ans = '\0' + ans;
		for(int i = 1;i < n;i ++){
			int end = ans.size() - 1;
			cin >> op;
			op = '\0' + op;
			// scanf("%s",op + 1);
			int len = op.size() - 1;
			// for(int i = 1;i <= end;i ++){
			// 	for(int j = 0;j < 2;j ++){
			// 		H[j][i] = (H[j][i - 1] * base[j] + ans[i] - '0' + 1) % mod[j]; 
			// 	}
			// }
			cmp = 0;
			H[0] = H[1] = 0;
			h[0] = h[1] = 0;//初始化
			for(int i = 1,k = end;i <= len && k >= 0;i++,k--){
				flag = 1;
				for(int j = 0;j < 2;j ++){
					H[j] = (H[j] + (ans[k] - '0' + 1) * p[j][end - k]) % mod[j];
					h[j] = (h[j] * base[j] + op[i] - '0' + 1) % mod[j];
					if(h[j] != H[j])flag = 0;
				}
				if(flag)cmp = i;
			}
			for(int i = cmp + 1;i <= len;i ++){
				ans.push_back(op[i]);
			}
		}
		// printf("%s\n",ans + 1);
		cout << ans << endl;
	}
	return 0;
}