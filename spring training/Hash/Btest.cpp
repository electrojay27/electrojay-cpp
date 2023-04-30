#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long
#define base 131
#define mod 1000000007

const int maxn = 1e5 + 10;
string a,b;
ull p[maxn];
int ans;
ull h[maxn];

// bool Search(ull Hash,int x){
// 	int l = 0,r = min(a.size(),b.size()) - x + 1;
// 	while(l <= r){
// 		int mid = (l + r) >> 1;
// 		if(h[mid] == Hash)return true;
// 		if(h[mid] > Hash)r = mid - 1;
// 		else l = mid + 1;
// 	}
// 	return false;
// }

void init(){
	p[0] = 1;
	for(int i = 1;i < maxn;i ++)p[i] = p[i-1] * base;
}

bool judge(int x)
{
	memset(h,0,sizeof(h));
	int cnt = 0;
	ull H = 0;
	for(int i = 0;i < x;i ++){
		H = H * base + a[i] - 'a' + 1;
	}
	h[cnt ++] = H;//存放长度为x的哈希值
	for(int i = x;i < a.size();i ++){
		H = H * base + a[i] - 'a' + 1 - (a[i - x] - 'a' + 1) * p[x];
		h[cnt ++] = H;
	}
	sort(h,h + cnt - 1);
	ull Hash = 0;
	for(int i = 0;i < x;i ++){
		Hash = Hash * base + b[i] - 'a' + 1;
	}

	if(binary_search(h,h + cnt - 1,Hash))return true;

	for(int i = x;i < b.size();i ++){
		Hash = Hash * base + b[i] - 'a' + 1 - (b[i - x] - 'a' + 1) * p[x];
		if(binary_search(h,h + cnt - 1,Hash))return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	while(cin >> a >> b){
		int r = min(a.size(),b.size());//最长的不可能超过最短的字符串
		int l = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(judge(mid)){
				ans =  mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}