#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 1e6 + 10;
i64 n,op,Size;
i64 heap[maxn];//堆
i64 ans,l;

void up(int x){
	while(x / 2 >= 1 && heap[x / 2] > heap[x]){
		swap(heap[x / 2],heap[x]);
		x >>= 1;
	}
}

i64 son_max(int x){
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
	cin >> heap[++ Size];
	// l += heap[Size];//总长
	up(Size);
}//插入

void Insert(i64 x){
	heap[++Size] = x;
	up(Size);
}//合并的木棍插入

i64 pop(){
	l = 0;
	// l -= heap[1];//去掉第一长的木棍
	for(int i = 1;i <= 2;i ++){
		l += heap[1];
		swap(heap[Size],heap[1]);
		heap[Size] = 0;
		Size --;
		down(1);
	}
	Insert(l);//插入
	return l;
}//删除

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		ans = 0;
		Size = 0;
		for(int i = 1;i <= n;i ++)insert();

		for(int i = 1;i < n;i ++){
			ans += pop();
		}

		cout << ans << endl;
	}
}

//逆向思考一下，首先要把长的剪断，逆过来也就是先合并短的，把它放回去，那不就是合并果子吗，问题就解决了，逆和正所需要的最小体力是一样
