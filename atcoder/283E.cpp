#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
const int mx = 0x3f3f3f3f;

int t = 1;

int dp[1005][2][2];

void solve() {
	// 283E 不难看出是关于行的dp
	// 前i行完成 <- 前i-1行完成 + 第i行是否需要操作
	// 考虑第i - 1行, 第i - 1行是否需要操作 还需要考虑第i - 2行和第i行
		
	// dp[i][j][k]: 最小次数操作前i行, 使得前i - 1行的元素没有孤立的;
	// j, k是标记第 i - 1 行和第 i 行 是否使用操作的标志位
	
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));	
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> a[i][j];
		}
	}
	
	memset(dp, 0x3f, sizeof(dp));
	
	// 前0行, 使得前-1行没有; 0行没有操作
	dp[0][0][0] = 0;
	// 0行有操作
	dp[0][0][1] = 1;
	
	for (int i = 1; i < h; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					// i - 2行
					vector<int> x(w, -1);
					if (i != 1) { x = a[i - 2]; }
					if (j == 1) {
						for (int m = 0; m < w; ++m) {
							x[m] = 1 - x[m];
						}
					}
					
					// 第i - 1行
					vector<int> y = a[i - 1];
					if (k == 1) {
						for (int m = 0; m < w; ++m) {
							y[m] = 1 - y[m];
						}
					}
					
					// 第i行
					vector<int> z = a[i];
					if (l == 1) {
						for (int m = 0; m < w; ++m) {
							z[m] = 1 - z[m];
						}
					}
					
					bool ok = true;
					for (int m = 0; m < w; ++m) {
						if ((x[m] != y[m] && y[m] != z[m])
						&& (m == 0 || y[m] != y[m - 1])
						&& (m == w - 1 || y[m] != y[m + 1])) {
							ok = false;
						}
					}
					
					if (i == h - 1) {
						for (int m = 0; m < w; ++m) {
							if ((z[m] != y[m])
							&& (m == 0 || z[m] != z[m - 1])
							&& (m == w - 1 || z[m] != z[m + 1])) {
								ok = false;
							}
						}
					}
					
					if (ok) {
						dp[i][k][l] = min(dp[i][k][l], dp[i - 1][j][k] + l);
					}
				}
			}
		}
	}
	
	int ans = mx;
	for (int j = 0; j < 2; ++j) {
		for (int k = 0; k < 2; ++k) {
			ans = min(ans, dp[h - 1][j][k]);
		}
	}
	cout << (ans == mx ? -1 : ans) << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}