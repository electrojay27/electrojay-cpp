#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x,y;
    int l,r,ans;
    l = 1,r = n;
    while(l < r){
        int mid = (l + r) / 2;
        cout << "?" << " " << l << " " << mid << " " << 1 << " " << n << endl;
        cin >> ans;
        if(ans < mid - l + 1)r = mid;
        else l = mid + 1;
    }
    x = r;
    l = 1,r = n;
    while(l < r){
        int mid = (l + r) / 2;
        cout << "?" << " " << 1 << " " << n << " " << l << " " << mid << endl;
        cin >> ans;
        if(ans < mid - l + 1)r = mid;
        else l = mid + 1;
    }
    y = r;
    cout << "!" << x << " " << y << endl;
    return 0;
}