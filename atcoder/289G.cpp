#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> b(n), c(m);
	for (int i = 0; i < n; ++i) { cin >> b[i]; }
	for (int i = 0; i < m; ++i) { cin >> c[i]; }
	
	// j = 1,2,...,M
	// 最大销售额
	// B[i] + C[j] >= Pj
	// P[j] 价格
	
	// B[i] >= P[j] - C[j]
	for (int j = 0; j < m; ++j) {
		// 220 * 5
		// 320 * 4
		// 420 * 3
		// 520 * 2
		// 620 * 1 里面选最大的乘积作为答案 => O(NM)!
		
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