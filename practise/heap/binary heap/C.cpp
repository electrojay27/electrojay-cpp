#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n,op,Size;
int heap[maxn];//堆

void up(int x){
	while(x / 2 >= 1 && heap[x / 2] > heap[x]){
		swap(heap[x / 2],heap[x]);
		x >>= 1;
	}
}

int son_max(int x){
	return 2 * x + (2 * x + 1 <= Size && heap[2 * x + 1] < heap[2 * x]);
}//寻找最大的子节点

void down(int x){
	while(son_max(x) <= Size && heap[son_max(x)] < heap[x]){
		int to = son_max(x);
		swap(heap[to],heap[x]);
		x = to;
	}
}

void insert(){
	int x;
	cin >> x;
	heap[++ Size] = x;
	up(Size);
}//插入

void pop(){
	swap(heap[Size],heap[1]);
	heap[Size] = 0;
	Size --;
	down(1);
}//删除

void top(){
	cout << heap[1] << endl;
}//头部输出

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		Size = 0;
		while(n --){
			cin >> op;
			if(op == 1)insert();
			else if(op == 2)top();
			else pop();
		}
	}
	return 0;
}