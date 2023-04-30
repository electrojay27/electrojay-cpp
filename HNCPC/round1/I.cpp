#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int H[510][maxn];//存在数
vector<int> V[510];
int temp1[maxn];
int temp2[maxn];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	while(cin>>N)
	{
		for(int i=0;i<510;i++)V[i].clear();
		memset(H,0,sizeof(H));
		for(int i=0;i<N;i++)
		{
			int M;cin>>M;
			for(int j=0;j<M;j++)
			{
				int x;
				cin>>x;
				H[i][x]=1;
				V[i].push_back(x);	
			}	
		}
		int Q;cin>>Q;
		while(Q--)
		{
			for(int i=0;i<maxn;i++)temp1[i]=0;
			for(int i=0;i<maxn;i++)temp2[i]=0;
			int X,Y;cin>>X>>Y;
			//cout<<"this"<<endl;
			for(int i=0;i<N;i++)
			{
				if(H[i][X])
				{
					//cout<<X<<endl;
					int len=V[i].size();
					for(int j=0;j<len;j++)
					{
						if(V[i][j]!=X&&V[i][j]!=Y)
						{
							temp1[V[i][j]]++;
							//cout<<V[i][j]<<endl;
						}
					}
				}
			}
			//cout<<"this"<<endl;
			for(int i=0;i<N;i++)
			{
				if(H[i][Y])
				{
					int len=V[i].size();
					for(int j=0;j<len;j++)
					{
						if(V[i][j]!=X&&V[i][j]!=Y)
						{
							temp2[V[i][j]]++;
							//cout<<V[i][j]<<endl;
						}
					}
				}
			}
			int ans=0;
			for(int i=0;i<maxn;i++)
				if(temp1[i]&&temp2[i])ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}