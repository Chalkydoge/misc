#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

struct Node {
	Node *son[26]{};
	int score = 0;
};



void solve() {
	int n;
	cin >> n;
	
	/*
		给你一棵树 N - 1个节点
		
		求: x = 1, 2, ..., N - 1
		
		子集V, V的导出子图恰好有x个连通分量时 取法有多少个
	
		x = 1, 1个连通分量
		1,2,3,4 | 1,2 2,3 3,4 | 1,2,3 2,3,4 | 1,2,3,4 = 10
		
		x = 2
		
	*/
	
	
	// 有N个连通分量时 方案数 => N - 1个连通分量
	// 树形dp
	// 转移方程?
	// u v 是一条树边 => 减少1
	f[N][v]
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}
