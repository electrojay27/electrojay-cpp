#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
string word[4010];
string op;
int ne[210];

int kmp(int a,int x)
{
	int m = 0;
	for(int i = 1,j = 0;i <= word[a].size();i ++)
	{
		while(j && (j + x == op.size() || word[a][i - 1] != op[j + x]))j = ne[j];
		if(word[a][i - 1] == op[j + x])j ++;
		
		m = max(m,j);
	}

	return m;
}

int judge(int x)
{
	ne[1] = 0;
	for(int i = 2,j = 0;i + x <= op.size();i ++){
		while(j && op[i - 1 + x] != op[j + x])j = ne[j];
		if(op[i - 1 + x] == op[j + x])j ++;
		ne[i] = j;
	}

	int m = 200;

	for(int i = 0;i < n;i ++)
	{
		m = min(m,kmp(i,x));
	}

	return m;
}

bool cmp(int bb,int xb,int l)
{
	int end = bb + l;

	while(bb < end){
		if(op[bb] < op[xb])return false;
		if(op[bb] > op[xb])return true;
		bb ++;
		xb ++;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n && n){
		// memset(ne,0,sizeof(ne));
		cin >> op;

		int l = 0,ans = 0,flag = 0;

		n --;

		for(int i = 0;i < n;i ++)cin >> word[i];

		for(int i = 0;i < op.size();i ++)
		{
			// for(int j = i + 1;j <= op.size();j ++)
			// {
			// 	if(judge(i,j)){
			// 		if(ans < j - i){
			// 			flag = 1;
			// 			ans = j - i;
			// 			l = i;
			// 		}else if(ans == j - i){
			// 			if(cmp(l,i,ans)){
			// 				l = i;
			// 			}
			// 		}
			// 	}
			// }
			int nowa = judge(i);
			if(nowa > ans || (nowa == ans && cmp(l,i,ans))){
				flag = 1;
				ans = nowa;
				l = i;
			}
		}

		if(flag){
			for(int i = l;i < l + ans;i ++)cout << op[i];
			cout << endl;
		}else cout << "IDENTITY LOST" << endl;
	}
	return 0;
}