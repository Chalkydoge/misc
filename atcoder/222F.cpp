#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;

int t = 1;

void solve() {
	int N;
	cin >> N;
	
	vector<vector<pair<int, int>> > g(N);
	
	for (int i = 1; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	vector<ll> d(N);
	for (int i = 0; i < N; ++i) {
		cin >> d[i];
	}
	
	vector<ll> m(N, 0);
	vector<ll> ans(N, 0);
	
	// m[u]: maximum expense of travel from Vertex u
	// to any vertex in the subtree rooted at u
	auto dfs1 = [&](auto&& dfs1, int u, int p) -> void {
		ll dis = 0;
		for (auto& pr: g[u]) {
			int v = pr.first;
			if (v == p) continue;
			
			dfs1(dfs1, v, u);
			dis = max(dis, max(d[v], m[v]) + pr.second);
		}
		
		m[u] = dis;
	};
	
	dfs1(dfs1, 0, -1);
	
	// u: 当前节点
	// p: u的父节点
	// c: 父节点p为根的子树中的最大贡献值
	auto dfs2 = [&](auto&& dfs2, int u, int p, ll c) -> void {
		// 假设我们已经知道了u的答案
		// 找u的子节点v的答案?
		
		// 最大值 次大值
		ll m1 = 0, m2 = 0;
		// 遍历u的所有子树
		for (auto& pr: g[u]) {
			int v = pr.first;
			if (v == p) continue;
			
			// 从子节点到u的最大费用可能
			ll cur_v = max(m[v], d[v]) + pr.second;
			if (cur_v > m1) {
				m2 = m1;
				m1 = cur_v;
			} else if (cur_v > m2) {
				m2 = cur_v;
			}
		}
		
		ans[u] = max(m1, c);
		
		for (auto& pr: g[u]) {
			int v = pr.first;
			if (v == p) continue;
			
			// 搜索子树 v的答案, 需要去掉v的影响
			ll cur_v = max(m[v], d[v]) + pr.second;
			if (cur_v == m1) {
				cur_v = m2;
			} else {
				cur_v = m1;
			}
			
			// 与之前的最大值进行比较
			cur_v = max(cur_v, c);
			dfs2(dfs2, v, u, max(cur_v, d[u]) + pr.second);
		}
	};
	
	dfs2(dfs2, 0, -1, 0);
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << '\n';
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