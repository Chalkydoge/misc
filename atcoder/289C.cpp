#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> c(m), sz(m);
	for (int i = 0; i < m; ++i) {
		cin >> sz[i];
		for (int j = 0; j < sz[i]; ++j) {
			int v;
			cin >> v;
			--v;
			c[i] |= (1 << v);
		}
			// cout << c[i] << '\n';
	}
	
	int ans = 0;
	for (int pick = 0; pick <= ((1 << m) - 1); ++pick) {
		int val = 0;
		for (int i = 0; i < m; ++i) {
			if (((pick >> i) & 1) == 1) {
				val |= c[i];	
			}
		}
		if (val == ((1 << n) - 1)) {
			++ans;
		}
	}
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