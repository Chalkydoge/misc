#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<string> s(n), t(m);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> t[i];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i].substr(3) == t[j]) {
				++ans;
				break;
			}
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
