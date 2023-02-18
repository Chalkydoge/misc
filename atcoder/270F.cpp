#include <bits/stdc++.h>
#define ll long long
#define inf LLONG_MAX

using namespace std;

int N, M;
int X[200050],Y[200050];
int a[200050],b[200050],z[200050];
int fa[200050], sz[200050];

struct edge {
	int u, v, w;
	edge(int _u = 0, int _v = 0, int _w = 0): u(_u), v(_v), w(_w) {}
	bool operator<(const edge& a) const { return w < a.w; }
};

vector<edge> edges;
ll ans = inf;

/* union-find */
void init(int N) {
	for (int i = 1; i <= N; ++i) {
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

void u(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		if (sz[fx] > sz[fy]) {
			fa[fy] = fx;
			sz[fx] += sz[fy];
		} else {
			fa[fx] = fy;
			sz[fy] += sz[fx];
		}
	}
}

int get_size(int x) { return sz[find(x)]; }

bool conn(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	return fx == fy;
}
/* union-find */

ll solve() {
	ll tmp = 0;
	init(N + 2);
	sort(edges.begin(), edges.end());
	
	for (auto& e: edges) {
		int from = e.u, to = e.v;
		int w = e.w;
		if (conn(from, to)) { continue; }
		u(from, to);
		tmp += w;
	}

	if (get_size(1) < N) { return inf; }
	else { return tmp; }	
}

int main() {
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i) { cin >> X[i]; }
	
	for (int i = 1; i <= N; ++i) { cin >> Y[i]; }
	
	for (int i = 1; i <= M; ++i) {
		cin >> a[i] >> b[i] >> z[i];
	}
	
	for (int i = 0; i < 4; ++i) {
		edges.clear();
		
		if ((i >> 1) & 1) {
			for (int j = 1; j <= N; ++j) {
				edges.emplace_back(j, N + 1, X[j]);	
			}		
		}
		
		if (i & 1) {
			for (int j = 1; j <= N; ++j) {
				edges.emplace_back(j, N + 2, Y[j]);	
			}
		}
		
		for (int j = 1; j <= M; ++j) {
			edges.emplace_back(a[j], b[j], z[j]);
		}
		
		ans = min(ans, solve());
	}
	
	if (ans == inf) { cout << -1 << endl; }
	else { cout << ans << endl; }
	
	return 0;	
}