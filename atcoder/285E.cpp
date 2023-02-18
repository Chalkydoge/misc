#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = (int)1e9 + 7;

int t = 1;

int N;

ll arr[5005];
ll g[5005];
ll dp[5005][5005];

/*
* dp[k][i]: 已经分配了k个holiday, 且上一个holiday在第i天

不分配holiday 找到前一个holiday 和 后一个 holiday, A min(x,y)

分配holiday 当天生产力为0


dp[k][i] -> dp[k + 1][j] 在第j天分配了holiday, 上一个在第i天

那么[i + 1, j - 1]区间内的工作日的效率可以计算吗?
距离可以发现是这样的

L = j - i - 1

x  y
1  L - 1
2  L - 2
3  ...
L / 2 L - L / 2

L是奇数, 例如L = 3, 那么 x = 1, 2, y = 2, 1  
工作和 总是 A[1...L/2] * 2

L是偶数, 例如L = 4, 那么 x = 1, 2, 3, y = 3, 2, 1
工作和等于  A[1..(L-1)/2] * 2 + A[L/2]

所以转移方程就是这样:

dp[k + 1][j] = max(dp[k][i] + cal(i, j) )

cal 是O(1)的(前缀和) 所以转移O1
最后答案是 max dp[1...N][1...N]

---

问题: 最后一段 dp[x][end] 从end + 1到N这些天怎么算?
固定一个first_free 枚举这个first_free 开始往后的结果

f[first][last]: 第一天为第first天, 最新一个是last天时的最大工作

f[first][new] = max(f[first][old] + cal(old + 1, new - 1))

最后对于last的每一个都补上和first之间差值的工作效率 就是答案!
*/

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);	
	while (t--) {
		cin >> N;
		
		// R - L - 1, [L, R]
		for (int i = 1; i <= N; ++i) { 
			cin >> arr[i];
		}
		memset(dp, -1, sizeof(dp));
		
		g[0] = 0;
		for (int i = 1; i <= N; ++i) {
			g[i] = g[i - 1] + arr[(i + 1) / 2];
		}
		
		dp[1][0] = 0;
		for (int i = 1; i < N; ++i) {
			for (int j = 0; j <= N; ++j) {
				if (dp[i][j] < 0) { continue; }
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
				dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + g[j]);
			}
		}
		
		ll ans = 0;
		for (int i = 0; i < N; ++i) {
			ans = max(ans, dp[N][i] + g[i]);
		}
		cout << ans << '\n';
		
	}
	
	return 0;
}