    #include <bits/stdc++.h>

    using i64 = long long;

    void solve()
    {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::set<int> num;

        for(int i = 0;i < n;i ++){
            std::cin >> a[i];
            num.insert(a[i]);
        }

        int mex = 0;
        while(num.count(mex))mex++;

        // std::cout << mex << "\n";

        if(!mex){
            std::cout << "Yes\n";
            return;
        }

        mex ++;
        std::set<int> all;

        if(n == 1 || n < mex){
            std::cout << "No" << "\n";
            return;
        }

        int l = 0,r = n - 1;
        int cnt = 1;
        while(l < n && a[l] != mex){
            if(!all.count(a[l])){
                all.insert(a[l]);
                // std::cout << a[l] << "\n";
                // std::cout << cnt << "\n";
            }
            l ++;
        }
        while(r >= 0 && a[r] != mex){
            if(!all.count(a[r])){
                all.insert(a[r]);
            }
            r --;
        }

        for(auto it = all.begin();it != all.end();it++){
            if(*it > mex)break;
            // std::cout << *it << "\n";
            cnt++;
        }

        if(cnt == mex)std::cout << "Yes\n";
        else std::cout << "No\n";
    }

    int main()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int t;
        std::cin >> t;
        while(t --){
            solve();
        }
        return 0;
    }