#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M;
int cnt = 0;
int mx = (int)1e6;

vector<vector<int>> g;
vector<int> vis;

void dfs(int u) {
	if (cnt >= mx) { return; }
	++cnt;
	vis[u] = 1;
	
	for (auto& v: g[u]) {
		if (v == 0) { continue; }
		if (!vis[v]) {
			dfs(v);
		}
	}
	vis[u] = 0;
}

int main() {
	cin >> N >> M;
	
	g.resize(N, vector<int>());
	vis.resize(N, 0);
	
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	// deg <= 10 -> 
	
	// 度数很小 -> 每个节点出发? 重复遍历?
	
	// min(10^6, K)
	
	dfs(0);
	cout << cnt << '\n';
	return 0;
}