#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n, m;
	
	cin >> n >> m;
	
	vector<vector<int>> g(n, vector<int>());
	vector<int> ind(n);
	
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
		++ind[u];
		++ind[v];
	}
	
	int cnt = 0, st = 0;
	for (int i = 0; i < n; ++i) {
		if (ind[i] > 2) {
			cout << "No\n";
			return;
		} else if (ind[i] == 1) {
			st = i;
			++cnt;
		}
	}
	
	vector<int> vis(n);
	
	auto dfs = [&](auto&& dfs, int u) -> void{
		for (auto& v: g[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				dfs(dfs, v);
			}
		}
	};
	
	// cout << cnt << ' ';
	if (cnt == 2 && m == n - 1) {
		
		vis[st] = 1;
		dfs(dfs, st);
		
		for (int i = 0; i < n; ++i) {
			if (vis[i] != 1) {
				cout << "No\n";
				return;
			}
		}
		
		cout << "Yes\n";		
		
	} else {
		cout << "No\n";
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
