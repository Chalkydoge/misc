#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, Q;

int id;
int ids[200005];
int deg[200005];
vector<int> g[200005];

void dfs(int u, int p) {
	ids[u] = id;
	
	for (auto& v: g[u]) {
		if (v != p && deg[v] < 2) {
			dfs(v, u);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		++deg[u];
		++deg[v];
	}
	
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (deg[i] == 1) {
			q.push(i);
		}
	}
		
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& nxt: g[cur]) {
			--deg[nxt];
			if (deg[nxt] == 1) {
				q.push(nxt);
			}
		}
	}
	
	id = 0;
	for (int i = 1; i <= N; ++i) {
		// 位于基环上的节点度数才会大于1
		if (deg[i] > 1) {
			++id;
			// 从基环向树枝进行dfs
			dfs(i, -1);
		}
	}
	
	cin >> Q;
	for (int i = 1; i <= Q; ++i) {
		int x, y;
		cin >> x >> y;
		if (ids[x] == ids[y]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}