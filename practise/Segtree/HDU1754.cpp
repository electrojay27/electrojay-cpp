#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e6 + 10;

i64 arr[N];

struct Segtree
{
	i64 val;
	i64 lazy;
	i64 maxn;
	Segtree () {
		val = lazy = 0;
	}
}seg[N * 4];

void init() {
	for (int i = 0; i < 4 * N; i++) {
		seg[i].maxn = seg[i].val = seg[i].lazy = 0;
	}
}

void build(int l,int r,int pos) {
	if (l == r) {
		seg[pos].val = arr[l];
		seg[pos].maxn = arr[l];
		return;
	}

	int mid = (l + r) / 2;
	build(l,mid,pos * 2);
	build(mid + 1,r,pos * 2 + 1);

	seg[pos].val = seg[pos * 2].val + seg[pos * 2 + 1].val;
	seg[pos].maxn = max(seg[pos * 2].maxn, seg[pos * 2 + 1].val);//最大值
}

void pushdown(int l,int r,int pos) {
	seg[pos * 2].lazy += seg[pos].lazy;
	seg[pos * 2 + 1].lazy += seg[pos].lazy;

	int mid = (l + r) / 2;
	seg[pos * 2].val += seg[pos].lazy * 1LL * (mid - l + 1);
	seg[pos * 2 + 1].val += seg[pos].lazy * 1LL * (r - mid);

	seg[pos].lazy = 0;
}

void interval_modify(int l,int r,int now_l,int now_r,int pos,int k_val) {
	if (l >= now_l && now_r >= r) {
		seg[pos].val += 1LL * k_val * (r - l + 1);
		seg[pos].lazy += k_val;
		return;
	} 

	pushdown(l,r,pos);
	
	int mid = (l + r) / 2;
	if (now_l <= mid) interval_modify(l,mid,now_l,now_r,2 * pos,k_val);
	if (now_r > mid) interval_modify(mid + 1,r,now_l,now_r,2 * pos + 1,k_val);

	seg[pos].val = seg[pos * 2].val + seg[pos * 2 + 1].val;
	seg[pos].maxn = max(seg[pos * 2].maxn, seg[pos * 2 + 1].maxn);
}

void single_point_update(int l,int r,int now_pos,int pos,int k_val) {
	if (l <= now_pos && r >= now_pos) {

	}
}

i64 query(int l,int r,int now_l,int now_r,int pos) {
	if (l >= now_l && r <= now_r) {
		// cout << "pos = " << pos << " " << seg[pos].val << "\n";
		return seg[pos].val;
	}
	if (l > now_r || r < now_l) return 0;

	int mid = (l + r) / 2;
	pushdown(l,r,pos);
	if (now_r <= mid) {
        return query(l, mid, now_l, now_r, pos * 2);
	}
    else if (now_l > mid) {
        return query(mid + 1, r, now_l, now_r, pos * 2 + 1);
    }
    else {
        return query(l, mid, now_l, mid, pos * 2) + query(mid + 1, r, mid + 1, now_r, pos * 2 + 1);
    }
}

i64 Query(int l,int r,int now_l,int now_r,int pos) {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


}