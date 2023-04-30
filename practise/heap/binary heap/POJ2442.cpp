#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define ll long long

const int maxn = 2e3 + 10;
int n,m,t;
int a[maxn];
int b[maxn];

struct Heap
{
	int heap[maxn],Size;

	void clear(){
		memset(heap,0,sizeof(heap));
		Size = 0;
	}//初始化

	void up(int x){
		while(x / 2 >= 1 && heap[x / 2] < heap[x]){
			swap(heap[x / 2],heap[x]);
			x >>= 1;
		}
	}//向上浮动

	int son_max(int x){
		return 2 * x + (2 * x + 1 <= Size && heap[2 * x + 1] > heap[2 * x]);
	}//寻找最大的子节点

	void down(int x){
		while(son_max(x) <= Size && heap[son_max(x)] > heap[x]){
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
}h;//大根堆结构体封装

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){

			cin >> m >> n;
			for(int i = 1;i <= n;i ++)
				cin >> a[i];
			
			for(int i = 1;i < m;i ++){
				h.clear();//清空
				
				sort(a + 1,a + 1 + n);//排序

				for(int j = 1;j <= n;j ++)
					cin >> b[j];
				
				sort(b + 1,b + 1 + n);

				for(int j = 1;j <= n;j ++)
					h.insert(a[1] + b[j]);
			
				for(int k = 2;k <= n;k ++)
					for(int j = 1;j <=n;j ++)
						if(a[k] + b[j] < h.top()){
							h.pop();
							h.insert(a[k] + b[j]);
						}

				for(int j = 1;j <= n;j ++)a[j] = h.heap[j];//继承
			}

			sort(a + 1,a + 1 + n);
			for(int i = 1;i <= n;i ++)cout << a[i] << " ";
			cout << endl;
		}
	}
}