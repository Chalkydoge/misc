#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n, m, x;
	cin >> n;
	
	// 2^10
	vector<int> a(n);
	vector<int> ok(100005, 0);

	for (int i = 0; i < n; ++i) {cin >> a[i]; }
	
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int b;
		cin >> b;
		ok[b] = 2;
	}
	
	cin >> x;
	
	auto dfs = [&](auto&& dfs, int u) -> void {
		if (u > x) { return; }
		if (ok[u] > 0) {
			return;
		}
		
		ok[u] = 1;
		for (int i = 0; i < n; ++i) {
			dfs(dfs, u + a[i]);
		}
	};
	
	dfs(dfs, 0);
	cout << (ok[x] == 1 ? "Yes\n" : "No\n");
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}