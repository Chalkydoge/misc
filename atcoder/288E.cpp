#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;

int t = 1;
int cost[5050][5050];
int f[5050][5050];

void solve() {
	int n, m;
	cin >> n >> m;
	
	// 买 第B{i}个 商品 最小代价是什么?
	// A[Bi]​​ + cost(Bi​,i−1)
	vector<int> a(n), c(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	
	vector<int> must(n);
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		--x;
		must[x] = 1;
	}
	
	// j <= i, cost(i,j) = min(c[i - j],..., c[i - 2], c[i - 1], c[i])
	// 表示说i个物品 假设你已经买掉了j个 剩下只有i - j个物品了
	// 它们带来的额外价值可选的最小值就是我们的cost[i][j]
	// 只能从 c[i - j], c[i - j + 1], ..., c[i] 这些里面可能的名次里面选(不可能更小了)
	
	vector<ll> dp(n + 1, inf);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		vector<ll> ndp(n + 1, inf);
		ll cost = inf;
		
		for (int j = 0; j <= i; ++j) {
			cost = min(cost, (ll)c[i - j]);
			ndp[j + 1] = min(ndp[j + 1], dp[j] + cost + a[i]);
			if (!must[i]) {
				ndp[j] = min(ndp[j], dp[j]);
			}
		}
		swap(dp, ndp);
	}
	
	ll ans = *min_element(dp.begin(), dp.end());
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