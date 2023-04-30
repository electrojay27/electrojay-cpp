#define lowbit(x) ((x) & -(x))

const int N = 1e6 + 10;

struct TA
{
	int t1[N];
	int t2[N];

	void add(int* t[],int x,int d){
		while(x < N){
			t[x] += d;
			x += lowbit(x);
		}
	}

	int sum(int* t[],int x){
		int ret = 0;
		int temp = x;
		while(x > 0){
			ret += t[temp];
			temp -= lowbit(temp);
		}
		return ret;
	}
};