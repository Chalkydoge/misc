#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, Q;

int main() {
	cin >> N;
	vector<vector<int>> g(N);
	
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	
	cin >> Q;
	
	/* queries */
	vector<vector<pair<int,int> > > query(N);
	for (int i = 0; i < Q; ++i) {
		int u, k;
		cin >> u >> k;
		--u;
		/* separated by querying nodes 'u' */
		query[u].emplace_back(i, k);
	}
	
	/* BFS, find farthest point */
	auto get_farthest = [&](int src) {
		vector<int> dis(N, N);
		queue<int> que;
		
		auto push = [&](int u, int d) {
			if (dis[u] > d) { dis[u] = d; que.push(u); }
		};
		
		push(src, 0);
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			for (int v: g[u]) {
				push(v, dis[u] + 1);
			}
		}
		
		return max_element(dis.begin(), dis.end()) - dis.begin();
	};
	
	/* from node 1, find farthest => L */
	int L = get_farthest(0);
	/* from node L, find farthest => R */
	int R = get_farthest(L);
	
	/* answer array */
	vector<int> ans(Q, -1);
	
	// Search from diameter nodes
	for (int root: {L, R}) {
		vector<int> path;
		auto dfs = [&](auto&& dfs, int u, int p) -> void {
			/* Each time, fill the answer with path
			* p1 -> p2 -> ... -> u
			* dis <= k => path[-k] is the answer
			*/
			for (const auto& val: query[u]) {
				int q = val.first;
				int k = val.second;
				
				if (k <= (int)path.size()) {
					ans[q] = path[(int)path.size() - k] + 1;
				}
			}
		
			path.push_back(u);
			for (int v: g[u]) {
				if (v != p) {
					dfs(dfs, v, u);
				}
			}
			path.pop_back();
		};
		
		dfs(dfs, root, -1);
	}
	
	for (int x: ans) {
		cout << x << '\n';
	}
	return 0;
}