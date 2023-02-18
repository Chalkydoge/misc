#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 4e9 + 10;

int t = 1, n, cnt;

ll x[205], y[205], p[205];

int vis[205];

void dfs(int u, ll s) {
	vis[u] = 1;
	++cnt;
	for (int v = 0; v < n; ++v) {
		if (vis[v]) continue;
		
		ll dx = abs(x[u] - x[v]), dy = abs(y[u] - y[v]);
		if (!vis[v] && dx + dy <= p[u] * s) {
			dfs(v, s);
		}
	}
}

bool check(ll mid) {
	// x1, y1 -> x2 y2
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		
		dfs(i, mid);
		
		if (cnt == n) { return true; }
		
	}
	return false;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> p[i];
	}
		
	ll left = 0, right = inf;
	while (left < right) {
		ll mid = (left + right) / 2;
		if (!check(mid)) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	cout << left << '\n';
}


int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}