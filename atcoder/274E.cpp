#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
int t = 1;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> x(n + m), y(n + m);
	for (int i = 0; i < n + m; ++i) {
		cin >> x[i] >> y[i];
	}
	

	// dp[i][S]: 当前在第i个坐标, 状态为S的最短耗时
	vector<vector<double> > dp(n + m, vector<double>(1 << (n + m), 1e18));
	
	for (int i = 0; i < n + m; ++i) {
		dp[i][1 << i] = hypot(x[i], y[i]);
	}
	
	for (int s = 1; s < 1 << (n + m); ++s) {
		double coef = pow(0.5, __builtin_popcount(s >> n));
		for (int i = 0; i < n + m; ++i) {
			if ((s >> i) & 1) {
				for (int j = 0; j < n + m; ++j) {
					if (!((s >> j) & 1)) {
						dp[j][s ^ (1 << j)] = min(dp[j][s ^ (1 << j)],
							dp[i][s] + hypot(x[i]-x[j],y[i]-y[j]) * coef);
					}
				}	
			}
		}
	}
	
	double ans = 1e18;
	for (int i = 0; i < n + m; ++i) {
		for (int s = (1 << n) - 1; s < 1 << (n + m); s += (1 << n)) {
			double coef = pow(0.5, __builtin_popcount(s >> n));
			ans = min(ans, dp[i][s] + hypot(x[i], y[i]) * coef);
		}
	}
	cout << setprecision(10) << ans << '\n';
}


int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}