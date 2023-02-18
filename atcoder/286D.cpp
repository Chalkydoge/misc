#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n, x;
	cin >> n >> x;
	
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	
	vector<int> f(10005, 0);
	f[0] = 1;
	int mx = 10000;
	
	for (int i = 0; i < n; ++i) {
		for (int j = mx; j > 0; --j) {
			for (int k = b[i]; k >= 1; --k) {
				if (j >= k * a[i]) {
					f[j] |= f[j - k * a[i]];
				}
			}
		}
	}
	
	cout << (f[x] == 1 ? "Yes" : "No") << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}