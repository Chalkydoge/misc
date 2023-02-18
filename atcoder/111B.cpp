#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
const ll mod = 998244353;
int t = 1;

int fa[400050];
int sz[400050];

void init(int n) {
	for (int i = 0; i <= n; ++i) {
		fa[i] = i;
	}	
}

int find(int x) {
	while (x != fa[x]) {
		fa[x] = fa[fa[x]];
		x = fa[x];
	}
	return x;
}

void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu != fv) {
		if (sz[fu] > sz[fv]) { sz[fu] += sz[fv]; fa[fv] = fu; }
		else { sz[fv] += sz[fu]; fa[fu] = fv; }
	}
}

void solve() {
	int N;
	cin >> N;
	
	int max_v = 0;
	vector<pair<int,int>> g;
	for (int i = 1; i <= N; ++i) {
		int u, v;
		cin >> u >> v;
		g.push_back({u, v});
		if (sz[u] == 0) { ++sz[u]; }
		if (sz[v] == 0) { ++sz[v]; }
		max_v = max(max_v, max(u, v));
	}

	init(max_v);
 
	for (auto& pr: g) {
		int u = pr.first, v = pr.second;
		merge(u, v);
	}
	
	map<int,int> cnt;
	for (auto& pr: g) {
		int f = find(pr.first);
		// 连通分量的边数
		++cnt[f];
	}
	
	int ans = 0;
	for (auto& pr: cnt) {
		int f = pr.first, edges = pr.second;
		// cout << "Node #" << f << ", Component edges count is: " << edges << '\n';
		int points = sz[f];
		// cout << "Contains " << points << " Nodes\n";
		if (edges > points - 1) {
			ans += points;
		} else {
			ans += points - 1;
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