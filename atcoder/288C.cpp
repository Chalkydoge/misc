#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int fa[200050];
int sz[200050];

int t = 1;

void init(int n) {
	for (int i = 0; i < n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
}

int find(int x) {
	while (x != fa[x]) {
		fa[x] = fa[fa[x]];
		x = fa[x];
	}
	return x;
}

void _u(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		if (sz[fx] > sz[fy]) { fa[fy] = fx; sz[fx] += sz[fy]; }
		else { fa[fx] = fy; sz[fy] += sz[fx]; }				
	}
}

void solve() {
	// 删除0/更多边 去掉环
	// 最少需要去掉多少?
	int n, m;
	cin >> n >> m;
	init(n);
	
	
	vector<pair<int,int>> g;
	
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
			
		_u(u,v);
		g.push_back({u, v});
	}
	
	
	map<int, int> cnt;
	// 所在连通分量有几条边
	for (int i = 0; i < m; ++i) {
		int f = find(g[i].first);
		cnt[f] += 1;
	}
	
	int ans = 0;
	for (auto& pr: cnt) {
		int f = pr.first, ed = pr.second;
		
		// cout << f << ' ' << ed << '\n';
		if (ed > sz[f] - 1) { ans += ed - (sz[f] - 1); }
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
