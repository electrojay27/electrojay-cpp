//题目大意：给定一个字符串，是否能由一个字符串复制一次再插入一个字符得到
//大概思路：哈希处理，然后判断哈希值是否相等，最开始直接wa一片，后面细微调整就第二部分数据tle TAT，后面将cin改成scanf后就wa了
//（真好再也不是tle）发现最后输出的地方有一个细微的判断细节，就是当没有符合答案的时候，两个字符串的长度也是0
//按照原本的判断条件就不会输出NOT POSSIBLE，这也就是另外一部分错的原因
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define base 123

const int maxn = 2e6 + 10;
char a[maxn];
string cnt1,cnt2,x,y;
ull Hash[maxn];
ull p[maxn];
int n,sum,cmp1,cmp2;


inline ull hasH(int l,int r){
	return Hash[r] - Hash[l - 1] * p[r - l + 1]; 
}

inline ull HasH(int l,int r,int point){
	return hasH(l,point - 1) * p[r - point] + hasH(point + 1,r);
}

int main()
{
	scanf("%d\n%s",&n,a + 1);

	sum = 0;

	if(!(n & 1)){
		printf("NOT POSSIBLE\n");
		return 0;
	}

	Hash[0] = 0;
	p[0] = 1;

	for(int i = 1;i <= n;i ++){
		Hash[i] = Hash[i - 1] * base + a[i] - 'A' + 1;
		p[i] = p[i-1] * base;
	}
	//不知道是在前面还是后面，所以利用两次判断来解决
	//假设插入字符在前面

	int to = (n + 1) >> 1;

	cmp1 = hasH(to + 1,n);
	for(int i = to + 1;i <= n;i ++)x.push_back(a[i]);
	for(int i = 1;i <= to;i ++){
		cmp2 = HasH(1,to,i);
		if(cmp1 == cmp2){
			sum ++;
			cnt1 = x;
			break;
		}
	}
	cmp2 = hasH(1,to - 1);
	for(int i = 1;i < to;i ++)y.push_back(a[i]);
	for(int i = to;i <= n;i ++){
		cmp1 = HasH(to,n,i);
		if(cmp1 == cmp2){
			sum ++;
			cnt2 = y;
			break;
		}
	}

	if(!sum){
		printf("NOT POSSIBLE\n");
	}else if(sum == 1 || cnt1 == cnt2){
		cout << (cnt1.size() ? cnt1 : cnt2) << "\n";
	}else{
		printf("NOT UNIQUE\n"); 
	}
	return 0;
}