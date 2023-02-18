#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

vector<int> tr1, tr2;
    
inline int lc(int x) { return 2 * x; }
inline int rc(int x) { return 1 + lc(x); }
    
// idx: 存区间的节点编号
// l, r: 当前的区间左右边界
// val: 区间的更新值
// pt: 当前进行单点更新的点坐标
void update(vector<int>& tree, int mode, int idx, int l, int r, int pt, int val) {
    if (l == r) {
        tree[idx] = val;
        return;
    }
        
    int m = (l + r) / 2;
    if (pt <= m) {
        update(tree, mode, lc(idx), l, m, pt, val);
    } else {
        update(tree, mode, rc(idx), m + 1, r, pt, val);
    }
    
    if (mode == 1) {
	    tree[idx] = max(tree[lc(idx)], tree[rc(idx)]);	
    } else {
	    tree[idx] = min(tree[lc(idx)], tree[rc(idx)]);
    }
}
    
// 求[L, R]区间内的最大值
// [l, r]是递归过程中发生修改的内容
int query(vector<int>& tree, int mode, int idx, int l, int r, int L, int R) {
    if (L <= l && r <= R) { return tree[idx]; }
    int ans = 0;
    int mid = (l + r) / 2;
    if (L <= mid) {
        ans = query(tree, mode, lc(idx), l, mid, L, R);
    }
    if (mid < R) {
    	if (mode == 1) { ans = max(ans, query(tree, mode, rc(idx), mid + 1, r, L, R)); }
        else { ans = min(ans, query(tree, mode, rc(idx), mid + 1, r, L, R)); }
    }
    return ans;
}

void solve() {
	// 283F 给你一个排列
	// 求 D[i] = min(|Pi - Pj| + |i - j|)
	// 下标差值 加上 排列元素差值
	
	// 首先 看到绝对值 直接就分类讨论 去掉符号
	/*
		对于一个给定的坐标i j位于左侧/右侧
		
		i <= j j在右侧
		
		i <= j: D[i] = min(|P[i] - P[j]| + j - i)
			P[i] <= P[j]
				P[j] - P[i] + j - i
				D[i] = min(P[j] - j + P[i] - i)
				维护在下标i之前 所有排列小于P[i]的元素 取最小值
			
			P[i] > P[j]
				D[i] = min(P[i] - P[j] + j - i)
				    P[i] - i - (P[j] - j)的min 因此需要找P[j] - j在i左侧的最大值
		
		i > j j在左侧
		
		i > j:
			P[i] <= P[j]:
				D[i] = min(P[j] - P[i] + i - j)
					P[j] - j - (P[i] - i)  最大值 => 找右侧的P[j] - j 最大值
			P[i] > P[j]
					P[i] - P[j] + i - j => P[j]+j最小值
		
	*/

	int N;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) { cin >> P[i]; }
	
	// 求 j <= i的部分
	for (int i = 0; i < N; ++i) {
		// 小于P[i]的P[j], min(P[j] + j)
		
		int q1 = query(tr2, 2, 1, 1, inf, 1, P[i] - 1);
		D[i] = min(D[i], P[i] + i - q1);
			
		// 大于P[i], max(P[j] - j)
		int q2 = query(tr1, 1, 1, 1, inf, P[i] + 1, N);
		D[i] = min(D[i], q2 - (P[i] - i));
		
		update(tr1, 1, 1, 1, inf, P[i], P[i] - i);
		update(tr2, 2, 1, 1, inf, P[i], P[i] + i);
	}
	
	// 再求 j > i的部分
	reset_tree();
	
	for (int i = N - 1; i >= 0; --i) {
		
	}
	
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}