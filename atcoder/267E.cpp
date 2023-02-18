#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
int t = 1;

void solve() {
	int n, m;
	cin >> n >> m;
	
	// 节点权重
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	// 选择一个点x 删除x的所有边
	// cost = (x点所有邻居节点的和)
	// N次操作 过程最大代价求最小值
	
	// 一种想法: 枚举这个上限值 lim
	// 每次都尝试删除 sum(u) <= lim的节点u
	// 然后将所有邻居节点v中的权值 -d[u]
	// 重复操作 直到 OK / 寄
	
	
	auto ok = [&](ll mid) -> bool {		
		queue<int> q;
		vector<int> vis(n, 0);
		vector<ll> s(n, 0);
		
		// get s
		for (int u = 0; u < n; ++u) {
			for (auto& v: g[u])
				s[u] += a[v];
		}
		
		// check with lim
		for (int u = 0; u < n; ++u) {
			if (s[u] <= mid) {
				vis[u] = 1;
				q.push(u);
			}
		}
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto& nxt: g[cur]) {
				// 去掉这个点
				if (!vis[nxt]) {
					s[nxt] -= a[cur];
					if (s[nxt] <= mid) {
						q.push(nxt);
						vis[nxt] = 1;	
					}
				}
			}
		}
		
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) { return false; }
		}
		return true;
	};
	
	ll ans = inf;
	ll left = 0, right = inf;
	while (left < right) {
		ll mid = (left + right) / 2;
		if (!ok(mid)) {
			left = mid + 1;
		} else {
			ans = mid;
			right = mid;
		}
	}
	
	cout << ans << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}