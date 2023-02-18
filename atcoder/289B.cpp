#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

int fa[105];



int find(int x) {
	while (x != fa[x]) {
		fa[x] = fa[fa[x]];
		x = fa[x];
	}
	return x;
}

void u(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		fa[fy] = fx;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	
	for (int i = 0; i < m; ++i) {
		int p;
		cin >> p;
		
		u(p, p + 1);
	}

	vector<int> vis(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			int fi = find(i);
			vector<int> tmp;
			for (int j = 1; j <= n; ++j) {
				if (find(j) == fi) { tmp.push_back(j); vis[j] = 1; }
			}
			
			int m = (int)tmp.size();
			for (int j = m - 1; j >= 0; --j) {
				cout << tmp[j] << ' ';
			}
			
		}
	}
	
	cout << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}