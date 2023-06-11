#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CMoney{
    private:
        int yuan,jiao,fen;
    public: 
        CMoney (int y,int j,int f) : yuan(y),jiao(j),fen(f) {};
        friend CMoney operator+ (CMoney& a,CMoney& b) {
            int y,j,f;
            y = a.yuan + b.yuan;
            j = a.jiao + b.jiao;
            f = a.fen + b.fen;
            if (f >= 10) {
                j += f / 10;
                f %= 10;
            }
            if (j >= 10) {
                y += j / 10;
                j %= 10;
            }
            return CMoney(y,j,f);
        }
        friend CMoney operator- (CMoney& a,CMoney& b) {
            int am = a.yuan * 100 + a.jiao * 10 + a.fen;
            int bm = b.yuan * 100 + b.jiao * 10 + b.fen;

            if (am > bm) {
                am -= bm;
            }  else {
                am = bm - am;
            }

            return CMoney(am / 100,am / 10 % 10,am % 10);
        }  
        void show(){
            cout<<yuan<<"元"<<jiao<<"角"<<fen<<"分"<<endl;
        }   
};
int main()
{
    int t;
    int y,j,f;
    string a;
    cin>>t;
    while(t)
    {
        cin>>y>>j>>f;
        CMoney money(y,j,f);
        while(1)
        {
            cin>>a;
            if(a == "stop")
            {
                money.show();
                break;
            }
            else if(a == "add"){
                cin>>y>>j>>f;
                CMoney money1(y,j,f);
                money=money + money1;
            }
            else{
                cin>>y>>j>>f;
                CMoney money1(y,j,f);
                money=money - money1;
            }
        }
        t--;
    }
    return 0;
}