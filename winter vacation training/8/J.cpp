#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
double ax,ay,bx,by,cx,cy,dx,dy;
double t,ans;
int n,m;
int id[maxn * 2];
struct node
{
	double x,y;
}a[maxn],b[maxn];

struct edge
{
	int u,v;
	double l;
}p[7 * maxn];

double L(node dx,node dy){
	return (dx.x - dy.x) * (dx.x - dy.x) + (dx.y - dy.y) * (dx.y - dy.y);
}

bool cmp_1(node dx,node dy)
{
	return dx.x < dy.x;
}

bool cmp_2(edge dx,edge dy){
	return dx.l < dy.l;
}

int find(int aa){
    return id[aa] == aa ? id[aa] : id[aa] = find(id[aa]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		int cnt = 0;
		int flag;
		ans = 0;

		for(int i = 1;i <= n + m;i ++)id[i] = i;

		cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
		for(int i = 1;i <= n;i ++){
			cin >> t;
			a[i].x = ax * t + bx * (1 - t);
			a[i].y = ay * t + by * (1 - t);
		}
		for(int i = 1;i <= m;i ++){
			cin >> t;
			b[i].x = cx * t + dx * (1 - t);
			b[i].y = cy * t + dy * (1 - t);
		}//存点

		sort(a + 1,a + 1 + n,cmp_1);
		sort(b + 1,b + 1 + m,cmp_1);

		for(int i = 1;i <= n;i ++){
			int l = 1,r = m;
			flag = 0;

			while(l < r - 2){
				int midl = l + (r - l) / 3;
				int midr = r - (r - l) / 3;
				if(L(a[i],b[midl]) < L(a[i],b[midr]))r = midr;
				else l = midl;
			}//三分进行缩小

			for(int j = l;j <= r;j ++){
				if(L(b[i],a[j]) < L(b[i],a[j + 1]) && j != r){
					if(j != 1)p[++cnt] = {i,n + j - 1,L(a[i],b[j - 1])};
					p[++cnt] = {i,n + j,L(a[i],b[j])};
					p[++cnt] = {i,n + j + 1,L(a[i],b[j + 1])};
					break;
				}

				if(j == r){
					if(j != 1)p[++cnt] = {i,n + j - 1,L(a[i],b[j-1])};
					p[++cnt] = {i,n + j,L(a[i],b[j])};
					if(j != m)p[++cnt] = {i,n+j+1,L(a[i],b[j+1])};
				}
			}
		}

		for(int i = 1;i <= m;i ++){
			int l = 1,r = n;
			flag = 0;

			while(l < r - 2){
				int midl = l + (r - l) / 3;
				int midr = r - (r - l) / 3;
				if(L(b[i],a[midl]) < L(b[i],a[midr]))r = midr;
				else l = midl;
			}

			for(int j = l;j <= r;j ++){
				if(L(a[i],b[j]) < L(a[i],b[j + 1]) && j != r){
					if(j != 1)p[++cnt] = {n + i,j - 1,L(b[i],a[j - 1])};
					p[++cnt] = {n + i,j,L(b[i],a[j])};
					p[++cnt] = {n + i,j + 1,L(b[i],a[j + 1])};
					break;
				}

				if(j == r){
					if(j != 1)p[++cnt] = {n + i,j - 1,L(b[i],a[j-1])};
					p[++cnt] = {n + i,j,L(b[i],a[j])};
					if(j != n)p[++cnt] = {n + i,j + 1,L(b[i],a[j+1])};
				}
			}
		}

		for(int i = 1;i < n;i ++)p[++cnt] = {i,i+1,L(a[i],a[i+1])};
		for(int i = 1;i < m;i ++)p[++cnt] = {i + n,i + 1 + n,L(b[i],b[i+1])};

		sort(p + 1,p + 1 + cnt,cmp_2);

		// int sum = 0;

		for(int i = 1;i <= cnt;i ++){
			if(find(p[i].u) != find(p[i].v)){
				id[find(p[i].u)] = find(p[i].v);
				ans += sqrt(p[i].l);
				// sum ++;
				// if(sum == n + m - 1)break;
			}
		}

		cout << fixed << setprecision(3) << ans << endl;
	}
}