// #include <bits/stdc++.h>
// using namespace std;
// bool shushu(int n){
//     if(n == 1)return false;
//     if(n == 2)return true;
//     for(int i=2;i<=sqrt(n);i++)if(n % i == 0)return false;
//     return true;
// }
// int main()
// {
//     int n;
//     while(scanf("%d",&n)!=EOF){
//         if(shushu(n))printf("Yes\n");
//         else printf("No\n");
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// const int eps = 1e-8;
// // double a[30];
// int main()
// {
//     double x;
//     int sum = 0;
//     for(int i=1;i<=28;i++){
//         scanf("%lf",&x);
//         if(x + eps >= 0.8)sum ++;
//     }
//     printf("%d\n",sum);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    scanf("%d",&i);
    int x,sum;
    sum = i;
    for(int j = 2;j <= 7;j ++){
        x = 0;
        int op = i;
        while(op>0){
            x += (op % 10);
            op /= 10;
        }
        i += x;
        sum += i;
    }
    printf("%d\n",sum);
    return 0;
}