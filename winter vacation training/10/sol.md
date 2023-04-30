## A - 树状数组 1

#### 题目大意

#### 有n个数，m个操作，一共有两个操作，1是给第x个加上k，2是求区间[x，y]的总和

#### 首先先了解[树状数组](https://blog.csdn.net/TheWayForDream/article/details/118436732?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167751242116782427483690%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167751242116782427483690&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-118436732-null-null.142^v73^wechat,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84&spm=1018.2226.3001.4187)是什么。这道题用树状数组会超时，所以得利用lowbit(x)运算，但还有另一种方法——线段树，线段树和树状数组都是一种数结构，不同的是线段树较为容易理解（~~可以不用lowbit(x)运算，赶起来比较快点~~），这里是详细分析的[线段树](https://blog.csdn.net/zearot/article/details/48299459?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167751266816782425147443%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167751266816782425147443&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-48299459-null-null.142^v73^wechat,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=%E7%BA%BF%E6%AE%B5%E6%A0%91&spm=1018.2226.3001.4187)，以及[模板](https://www.cnblogs.com/BCOI/p/8149181.html)，这样子理解完线段树后，这道题就可以解决了


## B - 线段树 1

#### 题目大意

#### 有n个数，m个操作，一共有两个操作，1是给区间[x，y]加上k，2是求区间[x，y]的总和

#### 与上一道不同的是第一个操作从单点改成区间，其实可以理解为单点是区间修改的特殊，也就是x = y时，那么对单点修改函数改变一下，即可解决问题


## C - 忠诚

#### 题目大意

#### 有 m 笔账 n 个问题，第i个问题为两个数字，表示第i笔账到第j笔账最少的一笔账是多少

#### 这相当于寻找一个区间里面最少的，那么可以将区间查询从总和改成求最小值即可


## D - 开关

#### 题目大意

#### 有n个灯，初始状态是关着的，然后0是区间[x，y]变成另一种状态，1是求区间[x,y]开着的灯有多少

#### 最开始想着加上去，最后对2取余，但是父节点就无法求得总数，那么就跟正常的遍历枚举没差，那么就利用^运算符，其他就没变，即可