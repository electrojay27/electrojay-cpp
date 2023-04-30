#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int cnt[maxn];
int n,x;
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		for(int i = 1;i <= n;i ++){
			cin >> x;
			h.insert(x);
			if(i % 2){
				for(int j = 1;j <= i / 2;j ++){
					cnt[j] = h.top();
					h.pop();
				}
				cout << h.top() << endl;
				for(int j = 1;j <= i / 2;j ++){
					h.insert(cnt[j]);//重新插入
				}
			}
		}
	}
	return 0;
}