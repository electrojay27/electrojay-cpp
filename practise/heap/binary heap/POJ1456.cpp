#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
#define ll long long

const int maxn = 1e5 + 10;
int n;

struct Heap
{
	int heap[maxn],Size;

	void clear(){
		memset(heap,0,sizeof(heap));
		Size = 0;
	}//初始化

	void up(int x){
		while(x / 2 >= 1 && heap[x / 2] > heap[x]){
			swap(heap[x / 2],heap[x]);
			x >>= 1;
		}
	}//向上浮动

	int son_max(int x){
		return 2 * x + (2 * x + 1 <= Size && heap[2 * x + 1] < heap[2 * x]);
	}//寻找最大的子节点

	void down(int x){
		while(son_max(x) <= Size && heap[son_max(x)] < heap[x]){
			int to = son_max(x);
			swap(heap[to],heap[x]);
			x = to;
		}
	}//向下调整

	void insert(int x){
		heap[++ Size] = x;
		up(Size);
	}//插入

	void pop(){
		swap(heap[Size],heap[1]);
		heap[Size--] = 0;
		down(1);
	}//删除

	int top(){
		return heap[1];
	}//头顶值
}h;//小根堆结构体封装

struct thing
{
	int day;
	int profit;

	bool operator < (const thing&t)const{
		return day < t.day;
	}
}p[maxn];//物品

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		h.clear();

		ll ans = 0;

		for(int i = 1;i <= n;i ++)
			cin >> p[i].day >> p[i].profit;

		sort(p + 1,p + 1 + n);//排序

		for(int i = 1;i <= n;i ++){
			if(p[i].day > h.Size)h.insert(p[i].profit);
			else if(p[i].day == h.Size){
				if(p[i].profit > h.top()){
					h.pop();
					h.insert(p[i].profit);
				}
			}
		}

		for(int i = 1;i <= h.Size;i ++)ans += h.heap[i];
		cout << ans << endl;
	}
}