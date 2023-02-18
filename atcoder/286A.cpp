#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n, p, q, r, s;
	cin >> n >> p >> q >> r >> s;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) { cin >> a[i]; }
	
	for (int i = 0; i <= q - p; ++i) {
		swap(a[p - 1 + i], a[r - 1 + i]);
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}