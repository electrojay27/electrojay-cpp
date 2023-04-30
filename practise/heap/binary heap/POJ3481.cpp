#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int maxn = 1e6 + 10;
int n,sum;

struct per
{
	int id,p;
}peo;

void Swap(per a,per b){
	int cnt;
	cnt =  a.id;
	a.id = b.id;
	b.id = cnt;
	cnt = a.p;
	a.p = b.p;
	b.p = cnt;
}

struct Heap_max
{
	per heap[maxn];
	int Size;

	void clear(){
		memset(heap,0,sizeof(heap));
		Size = 0;
	}//初始化

	void up(int x){
		while(x / 2 >= 1 && heap[x / 2].p < heap[x].p){
			Swap(heap[x / 2],heap[x]);
			x >>= 1;
		}
	}//向上浮动

	int son_max(int x){
		return 2 * x + (2 * x + 1 <= Size && heap[2 * x + 1].p > heap[2 * x].p);
	}//寻找最大的子节点

	void down(int x){
		while(son_max(x) <= Size && heap[son_max(x)].p > heap[x].p){
			int to = son_max(x);
			Swap(heap[to],heap[x]);
			x = to;
		}
	}//向下调整

	void insert(per x){
		heap[++ Size] = x;
		up(Size);
	}//插入

	void pop(){
		Swap(heap[Size],heap[1]);
		heap[Size--] = {0,0};
		down(1);
	}//删除

	int top(){
		return heap[1].id;
	}//头顶值
}h;//大根堆结构体封装

struct Heap_min
{
	per heap[maxn];
	int Size;

	void clear(){
		memset(heap,0,sizeof(heap));
		Size = 0;
	}//初始化

	void up(int x){
		while(x / 2 >= 1 && heap[x / 2].p > heap[x].p){
			Swap(heap[x / 2],heap[x]);
			x >>= 1;
		}
	}//向上浮动

	int son_max(int x){
		return 2 * x + (2 * x + 1 <= Size && heap[2 * x + 1].p < heap[2 * x].p);
	}//寻找最大的子节点

	void down(int x){
		while(son_max(x) <= Size && heap[son_max(x)].p < heap[x].p){
			int to = son_max(x);
			Swap(heap[to],heap[x]);
			x = to;
		}
	}//向下调整

	void insert(per x){
		heap[++ Size] = x;
		up(Size);
	}//插入

	void pop(){
		Swap(heap[Size],heap[1]);
		heap[Size--] = {0,0};
		down(1);
	}//删除

	int top(){
		return heap[1].id;
	}//头顶值
}H;//小根堆结构体封装

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	sum = 0;
	while(cin >> n && n){
		if(n == 1){
			cin >> peo.id >> peo.p;
			sum ++;//加一人
			h.insert(peo);
			H.insert(peo);
		}else if(n == 2){
			if(sum){
				cout << h.top() << endl;
				h.pop();
				sum --;
			}else cout << 0 << endl;
		}else{
			if(sum){
				cout << h.top() << endl;
				h.pop();
			}else cout << 0 << endl;
		}
	}

	return 0;
}