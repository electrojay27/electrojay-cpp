const int N = 1e6 + 10;

struct Heap
{
	int heap[N],size;

	void Swap(int a,int b){
		int temp = a;
		a = b;
		b = temp;
	}

	void clear(){
		for(int i = 0;i < N;i ++)heap[i] = 0;
		size = 0;
	}

	void up(int x){
		while(x / 2 >= 1 && heap[x / 2] > heap[x]){
			Swap(heap[x / 2],heap[x]);
			x >>= 1;
		}
	}

	int son_max(int x){
		return 2 * x + (2 * x + 1 <= size && heap[2 * x + 1] < heap[2 * x]);
	}

	void down(int x){
		while(son_max(x) <= size && heap[son_max(x)] < heap[x]){
			int to = son_max(x);
			Swap(heap[to],heap[x]);
			x = to;
		}
	}

	void insert(int x){
		heap[++ size] = x;
		up(size);
	}

	void pop(){
		Swap(heap[size],heap[1]);
		heap[size--] = 0;
		down(1);
	}

	int top(){
		return heap[1];
	}
};

