#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
const int INF=0x3f3f3f3f;
int F(int x,int y,int *C)//开始后多少分钟，总时长,第几个； 
{
	double temp=0;
	for(int i=0;i<6;i++)
		temp+=(double)C[i]*pow(x,i);
	return (int)abs(y*sin(temp));
}//返回还需要几分钟
struct node
{
	int ST,ET,DT; //化为分钟
	int Dx;//间隔时间
	int num[6];//系数
	void setS(string s)//开始时间 。 
	{
		ST=(s[0]-'0')*10*60+(s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
		//cout<<ST<<endl;
	}
	void setE(string s)//结束时间。 
	{
		ET=(s[0]-'0')*10*60+(s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
		//cout<<ET<<endl;
	}
	void setD(string s)//到达时间
	{
		DT=(s[0]-'0')*10*60+(s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
		//cout<<DT<<endl;
	}
	void setN()//设置系数 
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)cin>>num[i]; 
	}
	int Last()//最早时间。 
	{
		if(DT>ET)return INF;
		if(DT<ST)DT=ST;
		int ans=INF;
		Dx=ET-ST;//枚举开始时间， 
		for(int i=0;i<=Dx;i++)
		{
			if(ST+i<DT)continue;
			//cout<<DT-ST+i<<" "<<Dx<<" "<<endl;
			ans=min(ans,ST+i+F(i,Dx,num));
			//cout<<ans<<endl;
		}
		//cout<<ans<<"AAAAAA"<<endl;
		if(ans<=ET)return ans;
		else return INF;
	} 
}P[maxn];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	while(cin>>N)
	{
		memset(P,0,sizeof(P));
		int ans=INF;
		for(int i=0;i<N;i++)
		{
			string s1,s2,s3;
			cin>>s1>>s2>>s3;
			P[i].setS(s1);
			P[i].setE(s2);
			P[i].setD(s3);
			P[i].setN();
			ans=min(ans,P[i].Last());
		}
		if(ans!=INF){
			printf("%02d:%02d\n",ans/60,ans%60);
		}else{
			cout<<"Oh No!"<<endl;
		}
	}
	return 0;
}
/*
1
09:00 12:00 08:00 2 1 1
*/