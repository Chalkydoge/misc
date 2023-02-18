#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t;

bool vis[2005][2005];
void solve() {
	/*
		找交错路
		1 0 1 0 1...
		0 1 0 1 0...
	*/
	int n, m;
	cin >> n >> m;
	vector<int> c(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	
	vector<vector<int>> g(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	// p1, p2 => 01 or 10
	for(int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vis[i][j] = 0;
		}
	}
	
	queue<pair<int,int> > q;
	q.push({0, n - 1});
	vis[0][n - 1] = 1;

	bool ok = false;	
	int step = 0;
	while (!q.empty()) {
		int sz = (int)q.size();
		while (sz--) {
			auto cur = q.front();
			q.pop();
			
			int u = cur.first, v = cur.second;
			if (u == n - 1 && v == 0) { cout << step << '\n'; ok = true; break; }			

			vector<int> u1, u2;
			for (auto& w: g[u]) {
				if (c[w] == 0) { u1.push_back(w); }
				else { u2.push_back(w); }
			}
			
			vector<int> v1, v2;
			for (auto& w: g[v]) {
				if (c[w] == 0) { v1.push_back(w); }
				else { v2.push_back(w); }
			}
			
			for (auto& nu: u1) {
				for (auto& nv: v2) {
					if (!vis[nu][nv]) {
						vis[nu][nv] = 1;
						q.push({nu, nv});
						if (nu == n - 1 && nv == 0) { cout << step + 1 << '\n'; ok = true; break; }
					}
				}
			}
			
			for (auto& nu: u2) {
				for (auto& nv: v1) {
					if (!vis[nu][nv]) {
						vis[nu][nv] = 1;
						q.push({nu, nv});
						if (nu == n - 1 && nv == 0) { cout << step + 1 << '\n'; ok = true; break; }
					}
				}
			}			
		}
		if (ok) { break; }
		++step;
	}
	
	if (!ok)
		cout << -1 << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}
