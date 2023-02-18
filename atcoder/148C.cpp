#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int N, Q;
	cin >> N >> Q;
	
	vector<int> fa(N + 1);
	vector<int> cnt(N + 1);
	fa[1] = -1;
	
	for (int i = 2; i <= N; ++i) {
		int p;
		cin >> p;
		fa[i] = p;
		++cnt[fa[i]]; // 增加子树的大小()
	}
	
	for (int i = 1; i <= Q; ++i) {
		int m;
		cin >> m;
		
		set<int> vis;
		for (int j = 1; j <= m; ++j) {
			int u;
			cin >> u;
			vis.insert(u);
		}

		int ans = 0;		
		for (auto& u: vis) {
			// 遍历要求的每一个点
			// 单独关闭u的操作 == u关闭一次 + u的直接子节点操作一次
			ans += cnt[u];
			
			// 如果u被父节点覆盖到了 ==> 不需要额外做u的操作 ==> 减少一次
			if (vis.count(fa[u])) { --ans; }
			// 否则 补上一次 u关闭一次
			else { ++ans; }
		}
		cout << ans << '\n';
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
