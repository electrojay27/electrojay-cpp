```
struct Edge {
    int v; // 边的终点
    int w; // 边的权值（如果有）
    int next; // 下一个节点的编号（下一条边）
};
```
#### 上面是邻接表的结构体版本，邻接表适用于稀疏图，但是在一些算法中比较耗时，下面是较为完整模板
```
struct Edge {
    int v; // 边的终点
    int w; // 边的权值（如果有）
    int next; // 下一个节点的编号（下一条边）
};

const int MAXN = 1e6 + 10; // 假设最多有1e6个节点
int head[MAXN]; // head数组表示每个节点的邻居链表头指针
memset(head, -1, sizeof(head)); // 初始化为-1,同时避免有0的节点

Edge e = {v, w, head[u]}; // 新建一条边的结构体
head[u] = cnt; // 将该边的结构体插入到u的邻居链表中
cnt++; // 维护边的计数器

for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].v; // 获取节点v的编号
    int w = e[i].w; // 获取边(u,v)的权值（如果有）
    // 对节点v进行处理
}
```
#### 经过一定改变，成下面较为通用的版本
```
const int MAXN = 1e6 + 10; // 假设最多有1e6个节点
int head[MAXN]; // head数组表示每个节点的邻居链表头指针
memset(head, -1, sizeof(head)); // 初始化为-1,同时避免有0的节点

struct edge
{
    int end;//下一个节点
    int next;//下一个边
    int w;//边权
}e[maxn];

int cnt = 0;

void addedge(int a,int b,int c)
{
    cnt ++;
    e[cnt].next = head[a];
    head[a] = cnt;
    e[cnt].end = b;
    e[cnt].w = c;
}
```