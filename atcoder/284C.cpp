#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> g[105];

void dfs(vector<int>& vis, int u) {
	vis[u] = 1;
	for (auto& v: g[u]) {
		if (!vis[v]) {
			dfs(vis, v);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> vis(n, 0);
	int cnt = 0;
	
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			++cnt;
			dfs(vis, i);
		}
	}
	cout << cnt << '\n';
	return 0;
}